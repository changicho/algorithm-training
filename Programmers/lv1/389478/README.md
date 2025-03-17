# 2025 프로그래머스 코드챌린지 2차 예선 - 택배 상자 꺼내기

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/389478)

| 난이도 |
| :----: |
|  lv1   |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

2차원 배열을 직접 만들며 순회할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

2차원 배열을 직접 생성해 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 완전 탐색

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

직접 2차원 배열에 값을 채워넣고 num의 위치를 저장한다.

이후 num의 위치부터 y축의 끝까지 탐색하며 값이 존재하는 경우 count를 증가시킨다.

```cpp
int solution(int n, int w, int num) {
  int targetY = -1, targetX = -1;

  int board[101][101] = {
      0,
  };

  for (int y = 0, i = 1; y <= 100 && i <= n; y++) {
    for (int x = 0; x < w && i <= n; x++) {
      int xx = y % 2 ? x : w - 1 - x;

      board[y][xx] = i;
      if (i == num) {
        targetY = y;
        targetX = xx;
      }
      i++;
    }
  }

  int answer = 0;
  for (int y = targetY; y <= 100; y++) {
    if (board[y][targetX] > 0) {
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
