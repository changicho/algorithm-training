# 2786. Visit Array Positions to Maximize Score

[링크](https://leetcode.com/problems/visit-array-positions-to-maximize-score/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

패리티 비교는 짝수, 홀수 비교를 의미한다.

현재 수를 선택했을 때 직전에 선택한 수가 짝수, 홀수 여부에 따라 cost가 달라진다.

이전까지 짝수, 홀수를 선택했을 때의 최대값을 저장하며 구할 수 있다.

이를 순회하며 구할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

이전까지 짝수, 홀수를 선택했을 때의 최대값을 저장해야 한다.

두 값을 저장하므로 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     115      |    O(N)     |    O(1)     |

각 수마다의 패리티 비교는 짝수, 홀수 비교를 통해 비교할 수 있다.

만약 현재 수를 선택했을 때 현재 수의 패리티와 직전에 선택한 수의 패리티가 같은 경우 두 수를 더한다.

만약 다른 경우 x만큼 빼고 더할 수 있다.

따라서 각 수를 순회하며 이전까지 짝수, 홀수를 선택했을 때의 최대값을 갱신한다.

```cpp
long long maxScore(vector<int>& nums, int x) {
  int size = nums.size();

  long long even = nums.front() - (nums.front() % 2 ? x : 0);
  long long odd = nums.front() - (nums.front() % 2 ? 0 : x);

  for (int i = 1; i < size; i++) {
    if (nums[i] % 2 == 1) {
      odd = nums[i] + max(odd, even - x);
    } else {
      even = nums[i] + max(even, odd - x);
    }
  }

  return max(even, odd);
}
```

## 고생한 점
