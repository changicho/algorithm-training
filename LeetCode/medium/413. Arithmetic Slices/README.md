# 413. Arithmetic Slices

[링크](https://leetcode.com/problems/arithmetic-slices/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 경우를 탐색할 경우 range를 탐색 하는데 O(N^2), 하나의 range에서 유효성을 검사하는데 O(N)의 시간 복잡도가 소요된다.

따라서 O(N^3)의 시간 복잡도가 소요되며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 풀이한다.

이 경우 range만 순회해 풀이가 가능하며 이는 O(N^2)의 시간 복잡도가 필요하다.

혹은 끝나는 점에 대해서만 순회를 통해 판단할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

range에 대한 dp배열이 필요하며 이는 O(N^2)의 공간 복잡도를 사용한다.

끝나는 점에 대한 dp배열이 필요할 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법 (range)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1096     |   O(N^2)    |   O(N^2)    |

subArray의 길이를 늘려가며 탐색을 진행한다고 하자.

dp배열을 다음과 같이 설정하자

```cpp
dp[left][right]; // left ~ right 까지의 subArray가 유효한 경우 해당 배열의 diff값
```

현재 범위가 left ~ right 일 경우 left ~ (right + 1)이 유효한지는 다음과 같이 알 수 있다.

```cpp
dp[left][right] = dp[left][right - 1] == dp[right - 1][right] ? dp[left][right - 1] : LIMIT;
```

이는 직전 range에서 구한 값을 이용해 현재 range의 값이 유효한지를 알 수 있기 때문이다.

초기 값은 다음과 같다.

```cpp
for (int i = 1; i < size; i++) {
  dp[i - 1][i] = nums[i] - nums[i - 1];
}
```

이를 이용해 정답을 구할 수 있다.

```cpp
int numberOfArithmeticSlices(vector<int>& nums) {
  int size = nums.size();
  int limit = 2001;
  vector<vector<int>> dp(size, vector<int>(size, limit));

  for (int i = 1; i < size; i++) {
    dp[i - 1][i] = nums[i] - nums[i - 1];
  }

  int answer = 0;
  for (int length = 3; length <= size; length++) {
    for (int left = 0; left <= size - length; left++) {
      int right = left + (length - 1);
      int leftPart = dp[left][right - 1];
      int rightPart = dp[right - 1][right];

      if (leftPart == rightPart && leftPart != limit) {
        dp[left][right] = leftPart;
        answer += 1;
      }
    }
  }

  return answer;
}
```

### 동적 계획법 (end index)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

위 2차원 배열 동적 계획법을 보면 현재 dp값을 갱신할 때,

새로운 값의 경우 인접한 값만을 이용하는 것을 알 수 있다.

```javascript
// 기존 range를 a라 할 때 b와 a의 마지막 값의 diff만 비교함
[...a, b];
```

index를 이동시키며 해당 index를 range에서 끝나는 점으로 생각하고 dp값을 탐색한다.

dp 배열을 다음과 같이 정의하자.

```cpp
dp[i]; // i번째 index가 끝 range일 때의 arithmetic 개수
```

이 경우 일반식은 다음과 같이 구할 수 있다.

```cpp
int left = nums[i - 1] - nums[i - 2];
int right = nums[i] - nums[i - 1];

if (right == left) {
  dp[i] = dp[i - 1] + 1;
}
```

초기 값은 다음과 같다.

```cpp
// 0, 1의 경우 subArray의 크기가 3 이하이므로 0이다.
dp[0] = 0;
dp[1] = 0;
dp[2] = nums[2] - nums[1] == nums[1] - nums[0] ? 1 : 0;
```

정답으로 가능한 모든 경우의 수를 구해야한다.

이는 dp배열의 값들의 합으로 구할 수 있다.

(각 index가 마지막인 경우 가능한 경우의 수를 dp에 담고 있으므로)

이를 표현하면 다음과 같다.

```cpp
int numberOfArithmeticSlices(vector<int>& nums) {
  int size = nums.size();
  if (size < 3) return 0;

  vector<int> dp(size, 0);  // i번째 index가 끝 range일 때의 arithmetic 개수
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = nums[2] - nums[1] == nums[1] - nums[0] ? 1 : 0;

  int answer = dp[2];
  for (int i = 3; i < size; ++i) {
    int left = nums[i - 1] - nums[i - 2];
    int right = nums[i] - nums[i - 1];

    dp[i] = right == left ? dp[i - 1] + 1 : 0;
    answer += dp[i];
  }
  return answer;
}
```

## 고생한 점
