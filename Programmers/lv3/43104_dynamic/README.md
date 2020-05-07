# 43104. 타일 장식물

[링크](https://programmers.co.kr/learn/courses/30/lessons/43104#)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Level 3 |             |

## 설계

### 일반식

n번째 정사각형의 한 변의 길이의 일반식은 다음과 같다./

```cpp
dp[N] = dp[N-1] + dp[N-1];
```

N개의 타일로 구성된 직사각형의 둘레의 각 변의 길이는 다음과 같다.

```sh
긴 변 : dp[N-1] + dp[N]
작은 변 : dp[N]
```

따라서 둘레의 길이는 다음과 같다.

```cpp
2 * (2 * dp[N] + dp[N-1])
```

## 고생한 점