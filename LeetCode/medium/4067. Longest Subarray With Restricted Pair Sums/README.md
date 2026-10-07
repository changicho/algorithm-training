# 4067. Longest Subarray With Restricted Pair Sums

[링크](https://leetcode.com/problems/longest-subarray-with-restricted-pair-sums/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 값의 범위를 M이라 하자.

슬라이딩 윈도우를 이용하며 각 경우마다 검사하는데 O(NM)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수의 count에 O(M)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      43      |    O(NM)    |    O(M)     |

슬라이딩 윈도우를 사용해 현재 윈도우의 숫자들으 갯수를 관리한다.

현재 수를 추가했을 때 숫자들을 순회하며 이전 숫자들과 현재 수가 조건을 만족하는지 판단한다.

현재 수를 A, 이전 수를 B,C라 할 때 다음 조건들을 판단한다.

- A = B + C
- A + B = C
- A + C = B

이 때 B와 C가 같은 경우도 존재할 수 있으므로 이를 예외 처리한다.

```cpp
int maxSubarray(vector<int>& nums) {
  int count[501] = {
      0,
  };

  function<bool(int)> check = [&](int target) {
    for (int num = 0; num <= 500; num++) {
      if (count[num] == 0) continue;

      if (target == (num * 2)) {
        if (count[num] >= 2) {
          return false;
        }
      } else {
        if (target - num >= 0 && count[target - num] >= 1) {
          return false;
        }
      }
      if (num + target <= 500 && count[num + target] >= 1) {
        return false;
      }
    }
    return true;
  };

  int size = nums.size();

  int answer = 0;
  for (int left = 0, right = 0; right < size; right++) {
    while (left < right && !check(nums[right])) {
      count[nums[left]]--;
      left++;
    }

    count[nums[right]]++;

    answer = max(answer, right - left + 1);
  }
  return answer;
}
```

## 고생한 점
