# 4000. Largest Integer With Given Digit Sum

[링크](https://leetcode.com/problems/largest-integer-with-given-digit-sum/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 두 수를 N, S라 하자.

DFS를 사용할 경우 O(10^N)의 시간 복잡도를 사용한다.

동적 계획법을 사용할 경우 O(N \* S)의 시간 복잡도를 사용한다.

그리디 알고리즘을 사용해 구현할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

동적 계획법에 O(N \* S)의 공간 복잡도를 사용하며 직전값만 사용하므로 최적화하면 O(S)의 공간 복잡도를 사용한다.

그리디 알고리즘을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

최대 N개의 숫자를 사용하며 각 자리의 합이 S인 정답을 구해야한다.

앞자리부터 각 자리수를 최대한 9를 선택하며 불가능한경우 남은 가장 큰 수를 선택한다.

이렇게 생성한 정답을 반환한다.

```cpp
int largestInteger(int n, int s) {
  int answer = 0;

  for (int i = 0; i < n; ++i) {
    int cur = min(s, 9);
    answer = answer * 10 + cur;
    s -= cur;
  }
  if (s > 0) return -1;
  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* S)  |    O(N)     |

다음과 같은 dp배열을 생성한다.

```cpp
int dp[index][sum]; // index번째까지 숫자를 사용해 합이 남은 sum인 경우 최대값

int dp[0][s] = 0;

int dp[index][sum] = max(dp[index][sum], dp[index - 1][before - num] * 10 + num);
```

위 식을 이용해 초기값 -1으로 할당 후 값을 갱신해나간다.

이후 정답 케이스를 반환한다.

```cpp
int largestInteger(int n, int s) {
  vector<int> dp(s + 1, -1);
  dp[s] = 0;

  for (int i = 1; i <= n; i++) {
    vector<int> newDp(s + 1, -1);

    for (int before = s; before >= 0; before--) {
      if (dp[before] == -1) continue;

      for (int j = 0; j <= 9; j++) {
        if (before - j < 0) break;
        newDp[before - j] = max(newDp[before - j], dp[before] * 10 + j);
      }
    }

    swap(newDp, dp);
  }

  return dp[0];
}
```

## 고생한 점
