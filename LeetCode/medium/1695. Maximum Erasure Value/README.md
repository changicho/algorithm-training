# 1695. Maximum Erasure Value

[링크](https://leetcode.com/problems/maximum-erasure-value/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

각 숫자의 중복을 체크하는데 O(N)의 공간 복잡도를 갖는다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

슬라이딩 윈도우를 사용해 중복된 숫자가 없는 부분 배열의 합을 구한다.

왼쪽부터 순회하며 현재 원소가 이미 윈도우에 존재하는 경우, 현재 숫자가 중복되지 않을 때 까지 왼쪽 포인터를 이동시킨다.

이 과정에서 합을 갱신한다.

```cpp
int maximumUniqueSubarray(vector<int>& nums) {
  int size = nums.size();
  bool used[10001] = {
      false,
  };

  int answer = 0;
  int sum = 0;

  for (int left = 0, right = 0; right < size; right++) {
    while (left < right && used[nums[right]]) {
      used[nums[left]] = false;
      sum -= nums[left];
      left++;
    }

    sum += nums[right];
    used[nums[right]] = true;

    answer = max(answer, sum);
  }
  return answer;
}
```

## 고생한 점
