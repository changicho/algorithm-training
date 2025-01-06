# 3326. Minimum Division Operations to Make Array Non Decreasing

[링크](https://leetcode.com/problems/minimum-division-operations-to-make-array-non-decreasing/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 최대값을 M이라 하자.

모든 경우를 시뮬레이션을 이용해 탐색할 경우 O(N \* sqrt(M))의 시간 복잡도가 소요된다.

### 공간 복잡도

직전 값을 이용해 현재 값을 계산한다. 이 때 필요한 공간 복잡도는 O(1)이다.

### 시뮬레이션

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     284      | O(N \* sqrt(M)) |    O(1)     |

결과적으로 가장 마지막 값으로 갈 수록 커져야 한다.

따라서 가장 마지막 값부터 역순으로 순회하며 i번째 값이 i+1번째 값 보다 큰 경우 연산을 수행한다.

이 과정에서 불가능한 경우 -1을 반환한다.

```cpp
int calc(int cur) {
  int limit = sqrt(cur);

  for (int i = 2; i <= limit; i++) {
    if (cur % i != 0) continue;

    return i;
  }

  return -1;
}

int minOperations(vector<int>& nums) {
  int size = nums.size();

  int answer = 0;

  int next = INT_MAX;
  for (int i = size - 1; i >= 0; i--) {
    int cur = nums[i];

    while (cur > next) {
      answer++;
      cur = calc(cur);
    }

    if (cur == -1) return -1;

    next = cur;
  }
  return answer;
}
```

## 고생한 점
