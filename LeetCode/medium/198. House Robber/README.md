# 198. House Robber

[링크](https://leetcode.com/problems/house-robber/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우의수를 직접 탐색할 경우 2^N의 시간 복잡도가 소요되며 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 풀이할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

이전의 연산 결과를 저장해야 하므로 O(N)의 공간 복잡도가 필요하다.

혹은 직전, 직직전의 연산 결과만 필요하므로 O(1)의 공간 복잡도로 문제를 해결이 가능하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

이전까지의 연산 결과를 이용해 현재 가능한 최대 이익을 구할 수 있다.

dp배열을 다음과 같이 정의한다.

- index번째 집 까지 훔쳤을 때의 최대 이익

일반식은 다음과 같이 설정한다.

```cpp
// 현재 집을 방문하는 경우 vs 현재 집을 방문하지 않은 경우
dp[index] = max(dp[index - 1], nums[i] + max(dp[i - 2], dp[i - 3]));
```

초기값은 다음과 같다.

```cpp
dp[0] = nums[0];
dp[1] = max(nums[0], nums[1]);
dp[2] = max(dp[1], dp[0] + nums[2]);
```

이를 이용해 정답을 구한다.

이 때 nums의 크기가 작은 경우 예외처리한다.

```cpp
int rob(vector<int>& nums) {
  int size = nums.size();
  vector<int> dp(size, 0);
  dp[0] = nums[0];
  if (size == 1) return dp.back();

  dp[1] = max(nums[0], nums[1]);
  if (size == 2) return dp.back();

  dp[2] = max(dp[1], dp[0] + nums[2]);

  for (int i = 3; i < size; i++) {
    dp[i] = max(dp[i - 1], nums[i] + max(dp[i - 2], dp[i - 3]));
  }

  return dp.back();
}
```

### 동적 계획법 O(1)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

일반식에서 사용하는 값은 직전값과, 직직전값 두가지이다.

따라서 두 값만을 이용해 문제를 풀이할 수 있다.

```cpp
int rob(vector<int>& nums) {
  int second = 0, first = 0;

  for (int& num : nums) {
    int cur = max(second + num, first);

    second = first;
    first = cur;
  }

  return first;
}
```

### 동적 계획법 홀수,짝수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

혹은 홀수번째와 짝수번째에 대해서 분기처리해 문제를 풀이할 수 있다.

```cpp
int rob(vector<int>& nums) {
  int size = nums.size();
  int even = 0;
  int odd = 0;

  for (int i = 0; i < size; i++) {
    if (i % 2 == 0) {
      even = max(even + nums[i], odd);
    } else {
      odd = max(even, odd + nums[i]);
    }
  }

  return max(even, odd);
}
```

## 고생한 점
