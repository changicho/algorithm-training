# 8958. OX퀴즈

[링크](https://www.acmicpc.net/problem/8958)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Bronze II |   52.112    |

## 설계

### 시간 복잡도

퀴즈의 결과는 총 5개이다.

각 문자열의 길이는 최대 80이며, 정답의 개수를 셀 때 O(N)의 시간복잡도가 발생한다.

따라서 제한시간 1초 내에 충분하다.

### 공간 복잡도

정답은 최대 (81+80)/2 까지 가능하며 이는 int형으로 충분하다.

### counting

continuous를 통해 연속된 수를 판별한다.

```cpp
int score = 0;
int continuous = 0;

for (char c : line) {
  if (c == 'O') {
    continuous += 1;
    score += continuous;
  } else {
    continuous = 0;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
