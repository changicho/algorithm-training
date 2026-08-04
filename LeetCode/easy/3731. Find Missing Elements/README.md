# 3731. Find Missing Elements

[링크](https://leetcode.com/problems/find-missing-elements/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 숫자의 범위를 M이라 하자.

실제 숫자의 범위와 존재 여부를 저장하는데 O(N)의 시간 복잡도를 사용한다. 이후 빠진 숫자를 순차적으로 찾는데 O(M)의 공간 복잡도를 사용한다.

### 공간 복잡도

방문 여부에 O(M)의 공간 복잡도를 사용한다. 정답에 O(N)의 시간 복잡도를 사용한다.

### hash set & 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |  O(N + M)   |

배열을 순회하며 숫자의 범위 (최소값, 최대값)을 구하고 존재 여부를 배열에 표시한다.

이후 실제 숫자의 범위를 순회하며 빠진 숫자를 찾는다.

```cpp
vector<int> findMissingElements(vector<int>& nums) {
  int left = nums[0], right = nums[0];

  bool b[101] = {
      0,
  };

  for (int& num : nums) {
    b[num] = true;

    left = min(left, num);
    right = max(right, num);
  }

  vector<int> answer;
  for (int i = left; i <= right; i++) {
    if (b[i] == false) answer.push_back(i);
  }
  return answer;
}
```

## 고생한 점
