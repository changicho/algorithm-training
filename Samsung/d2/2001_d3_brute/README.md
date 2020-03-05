# 2001. 파리 퇴치

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PzOCKAigDFAUq&categoryId=AV5PzOCKAigDFAUq&categoryType=CODE)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|   d2   |    69.20    |

## 설계

### 최대값

N은 15이하, 파리의 수는 30 이하

15 X 15 X 30 = 6750

### 반복문

가능한 모든 경우를 순회한다

```cpp
for (int y = 0; y < N - M + 1; y++)
  for (int x = 0; x < N - M + 1; x++)
```

위 반복문 내부에

```cpp
for (int i = 0; i < M; i++)
  for (int j = 0; j < M; j++)
```

로 구성된 4중 반복문을 돌린다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     5 ms     |      1 ms      |

## 고생한 점
