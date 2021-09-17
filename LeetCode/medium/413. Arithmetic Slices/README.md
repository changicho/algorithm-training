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

### 공간 복잡도

range에 대한 dp배열이 필요하며 이는 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1568     |   O(N^2)    |   O(N^2)    |

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

## 고생한 점
