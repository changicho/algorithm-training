# 2005. 파스칼의 삼각형

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P0-h6Ak4DFAUq&categoryId=AV5P0-h6Ak4DFAUq&categoryType=CODE)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|   d2   |    66.4     |

## 설계

### [10][10] 사이즈 배열

N의 최대 크기가 10까지밖에 되지 않으므로 직접 모든 경우를 계산했다.

```cpp
// dp
pascal[y][x];
// 일반식
pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
// 초기값
pascal[0][0] = 1;
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     6 ms     |      1 ms      |

## 고생한 점
