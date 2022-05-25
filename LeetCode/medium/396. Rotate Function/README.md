# 396. Rotate Function

[링크](https://leetcode.com/problems/rotate-function/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

모든 index를 시작점으로 지정하고 완전 탐색을 진행했을 때 시간 복잡도는 O(N^2)이다.

이는 제한시간 내에 불가능하다.

수식을 이용한 규칙과 동적 계획법을 이용할 수 있다.

이 경우 dp값이 구해졌을 때 한번의 순회로 풀이가 가능하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 이용해 각 index마다의 값을 구할 경우 O(N)의 공간 복잡도를 사용한다.

직전 값만을 이용해 구하므로 배열을 사용하지 않을 경우 O(1)의 공간 복잡도를 사용한다.

### 수학 & 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     258      |    O(N)     |    O(N)     |

입력받은 num를 `[a b c d e]` 라고 하자.

각 경우마다 F의 값은 아래와 같다.

```plain_text
- F(0) = (0 * a) + (1 * b) + (2 * c) + (3 * d) + (4 * e) = 0 + b + 2c + 3d + 4e
- F(1) = (1 * a) + (2 * b) + (3 * c) + (4 * d) + (0 * e) = a + 2b + 3c + 4d + 0
- F(2) = (2 * a) + (3 * b) + (4 * c) + (0 * d) + (1 * e) = 2a + 3b + 4c + 0 + e
```

여기서 우리는 다음과 같은 규칙을 발견할 수 있다.

```plain_text
F(1) - F(0) = a + b + c + d - 4e = a + b + c + d + e - 5e
F(1) = F(0) + a + b + c + d + e - 5e = F(0) + SUM - N*e

F(2) - F(1) = a + b + c + e - 4d = a + b + c + d + e - 5d
F(2) = F(1) + a + b + c + d + e - 5d = F(1) + SUM - N*d

F(K) = F(K-1) + SUM - N * ((K-1)th element from end of array)
F(K) = F(K-1) + SUM - N * (array [N - 1 - (K-1)]) = F(K-1) + SUM - N * (array [N - K])
```

즉 이를 이용해 F(i)를 구하기 위해선 F(i-1)의 값을 알아야 한다.

맨 처음 첫번째 index에서 시작하는 F(1)을 구하고, 이를 이용해 나머지 F함수의 값들을 구한뒤 정답을 구한다.

이를 구현하면 다음과 같다.

```cpp
int maxRotateFunction(vector<int>& nums) {
  int size = nums.size();

  vector<int> dp(size, 0);
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += nums[i];
    dp[0] += i * nums[i];
  }

  int maximum = dp[0];
  for (int i = 1; i < size; i++) {
    dp[i] = dp[i - 1] + sum - size * nums[size - i];
    maximum = max(maximum, dp[i]);
  }

  return maximum;
}
```

### 수학 & 동적 계획법 (공간 최적화)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     173      |    O(N)     |    O(1)     |

위 방법에서 직전값만을 알면 되므로 배열 대신 값을 이용해 최적화한다.

```cpp
int maxRotateFunction(vector<int>& nums) {
  int size = nums.size();

  int cur = 0;
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += nums[i];
    cur += i * nums[i];
  }

  int maximum = cur;
  for (int i = 1; i < size; i++) {
    cur = cur + sum - size * nums[size - i];
    maximum = max(maximum, cur);
  }

  return maximum;
}
```

## 고생한 점
