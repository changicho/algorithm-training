# 9251. LCS

[링크](https://www.acmicpc.net/problem/9251)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   41.179    |

## 설계

### 시간 복잡도

문자의 길이는 최대 1000 이다.

모든 경우를 탐색하더라도 1000^2 이므로 제한 시간 내에 충분하다.

시간을 줄이기 위해 동적 계획법을 사용한다.

LCS를 구하는 방법의 시간 복잡도는 다음과 같다.

첫번째 단어의 길이 A, 두번째 단어의 길이 B

시간 복잡도는 O(AB)

### 공간 복잡도

공통 문자열의 최대 길이는 1000 이므로 최대 크기는 1000 이다.

2차원 dp 배열을 1000^2 사이즈로 생성해 사용한다.

### 동적 계획법

dp를 이용해 이전에 구해둔 LCS를 이용해 갱신할 수있다.

첫번째 단어의 index, 두번째 단어의 index를 각각 idx1, idx2 라고 하자.

idx1, idx2를 증가시키며 같은 문자가 나오면 이전까지의 LCS의 길이에 +1을 한다.

다른 문자가 나온 경우 idx1 - 1, idx2 - 1 번째 (인접한 이전 값) 중에 큰 값을 가진다.

즉 값을 구하는 규칙은 다음과 같다.

1. String1[n], String2[k]가 같다면 : [n, k] == [n-1, k-1] + 1
2. String1[n], String2[k]가 다르면 : [n, k] == [n-1, k]와 [n, k-1] 중 큰 값

따라서 dp는 다음과 같다.

```cpp
dp[idx1][idx2] // 각 위치에서의 LCS (최장 공통 부분 수열)
// idx1 : 첫 번째 단어의 index
// idx2 : 두 번째 단어의 index
```

dp의 초기 값은 다음과 같다

```cpp
dp[][] = { 0, }
```

dp의 갱신은 다음과 같다.

- first_word[idx1] == second_word[idx2]
  - dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + 1
- 그 외의 경우
  - dp[idx1][idx2] = max(dp[idx1 - 1][idx2], lcs[idx1][idx2 - 1]);

```cpp
for (int idx1 = 1; idx1 <= first.length(); idx1++) {
  for (int idx2 = 1; idx2 <= second.length(); idx2++) {
    if (first[idx1 - 1] == second[idx2 - 1]) {
      dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + 1;
    } else {
      dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       0        |

## 고생한 점
