# C - Sierpinski carpet

[링크](https://atcoder.jp/contests/abc357/tasks/abc357_c)

| 난이도 |
| :----: |
|  250   |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

재귀 호출을 이용해 구현할 경우 O(3^2N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 배열에 O(3^2N)의 공간 복잡도가 필요하다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |   O(3^2N)   |   O(3^2N)   |

현재 범위를 9등분한 뒤 중앙의 3x3 부분 빈칸으로 변경하고 나머지 다시 재귀호출한다.

```cpp
vector<string> solution(int n) {
  vector<string> board(pow(3, n), string(pow(3, n), '#'));

  function<void(int, int, int)> recursive = [&](int n, int x, int y) {
    if (n == 0) {
      board[y][x] = '#';
      return;
    }

    int size = pow(3, n - 1);
    recursive(n - 1, x, y);
    recursive(n - 1, x + size, y);
    recursive(n - 1, x + size * 2, y);

    recursive(n - 1, x, y + size);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        board[y + size + i][x + size + j] = '.';
      }
    }
    recursive(n - 1, x + size * 2, y + size);

    recursive(n - 1, x, y + size * 2);
    recursive(n - 1, x + size, y + size * 2);
    recursive(n - 1, x + size * 2, y + size * 2);
  };

  recursive(n, 0, 0);

  return board;
}
```

## 고생한 점
