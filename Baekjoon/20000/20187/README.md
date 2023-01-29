# 20187. 종이접기

[링크](https://www.acmicpc.net/problem/20187)

| 정답률  |  난이도  |
| :-----: | :------: |
| 45.184% | 골드 III |

## 설계

### 시간 복잡도

입력받은 수를 K라 하자.

종이를 접은 후 생기는 구멍의 갯수는 2^(2K) 이다.

종이를 접으며 0,0 위치의 구멍이 변하는 위치를 판단하고, 이를 복구해 나간다.

이 경우 종이를 접는 순회에 O(K)의 시간 복잡도를, 이를 복구하는데 O(2^(2K))의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 추가 공간을 사용할 경우 O(2^(2K))의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(2^(2K))  |  O(2^(2K))  |

0,0에 위치한 구멍을 H라 했을 때 종이를 모두 접은 후 H가 어떻게 변하는지 복구하며 0,0의 구멍의 종류를 알 수 있다.

이후 이를 토대로 나머지 위치의 구멍들을 복구 가능하다.

종이를 상하, 좌우로 접었을 때 0,0 위치의 상하, 좌우가 반전되는 경우는 다음과 같다.

- 상하 반전 X & Down : 상하 반전 됨
- 상하 반전 O & UP : 상하 반전 안됨
- 좌우 반전 X & Right : 좌우 반전 됨
- 좌우 반전 O & Left : 좌우 반전 안됨

이를 이용해 종이를 접는 순서를 순회하며 반전 여부를 판단 후 0,0의 구멍을 토대로 복구한다.

```cpp
int solution(int size, vector<char> &folds, int hole) {
  bool isRowReversed = false, isColReversed = false;

  for (char &f : folds) {
    if (f == 'D' && !isRowReversed) {
      isRowReversed = true;
    } else if (f == 'U' && isRowReversed) {
      isRowReversed = false;
    } else if (f == 'R' && !isColReversed) {
      isColReversed = true;
    } else if (f == 'L' && isColReversed) {
      isColReversed = false;
    }
  }

  int ret = hole;
  int y = hole / 2;
  int x = hole % 2;

  if (isRowReversed) {
    y += 1;
    y %= 2;
  }
  if (isColReversed) {
    x += 1;
    x %= 2;
  }

  return y * 2 + x;
}

// fill board
int answer = solution(K, folds, H);

int size = 1 << K;
int start = answer;

int board[1 << 8][1 << 8] = {-1};
board[0][0] = start;

for (int y = 0; y < size; y++) {
  if (y > 0) {
    board[y][0] = (board[y - 1][0] + 2) % 4;
  }
  for (int x = 1; x < size; x++) {
    board[y][x] =
        board[y][x - 1] % 2 == 0 ? board[y][x - 1] + 1 : board[y][x - 1] - 1;
  }
}
```

## 고생한 점
