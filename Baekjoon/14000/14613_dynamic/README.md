# 14613. 너의 티어는?

[링크](https://www.acmicpc.net/problem/14613)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   56.633    |

## 설계

### 시간 복잡도

승리, 패배, 비기기 3가지 경우가 존재한다. 이를 20번동안 모든 경우를 탐색할 경우 걸리는 시간 복잡도는

3^20 이고 이는 3,486,784,401 이므로 제한시간 2초 내에 불가능하다.

이용자가 얻을 수 있는 점수는 1000 ~ 3000 점 사이임이 분명하므로, 각 게임마다 점수에 대해서 탐색을 진행한다.

각 점수와 게임 수에 해당하는 dp 배열을 만들 경우 시간 복잡도는 다음과 같다.

```cpp
// 점수 탐색 (1000 ~ 3000) * 게임 수
2000 * 20
```

이는 40,000 이므로 제한시간 내에 충분하다.

### 공간 복잡도

소숫점 최대 8자리 까지 출력하므로 double형으로 선언한다.

### 동적 계획법

dp 배열은 다음과 같다.

```cpp
dp[게임수][점수]
```

dp의 일반식은 다음과 같다.

```cpp
// G : 게임 횟수
// S : 점수
dp[G][S] = dp[G-1][S-50] * W + dp[G-1][S+50] * L + dp[G-1][S] * D
```

이를 첫번째 게임부터 탐색을 진행해 돌린다.

```cpp
dp[0][2000] = 1;
for (int gameCount = 1; gameCount <= 20; gameCount++) {
  for (int score = 1000; score <= 3000; score++) {
    if (dp[gameCount - 1][score] == 0) continue;

    dp[gameCount][score - 50] += dp[gameCount - 1][score] * L;
    dp[gameCount][score + 50] += dp[gameCount - 1][score] * W;
    dp[gameCount][score] += dp[gameCount - 1][score] * D;
  }
}
```

이후 최종단계의 score별로 확률을 구한다.

```cpp
for (int score = 1000; score <= 3000; score++) {
  if (1000 <= score && score <= 1499) {
    rankCount[0] += dp[20][score];
  } else if (1500 <= score && score <= 1999) {
    rankCount[1] += dp[20][score];
  } else if (2000 <= score && score <= 2499) {
    rankCount[2] += dp[20][score];
  } else if (2500 <= score && score <= 2999) {
    rankCount[3] += dp[20][score];
  } else {
    rankCount[4] += dp[20][score];
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
