# E - Weighted Tic-Tac-Toe

[링크](https://atcoder.jp/contests/abc349/tasks/abc349_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

주어진 3^2 배열의 원소의 수를 N이라 하자 (N = 9)

각 순서마다 좌표를 중복되지 않게 선택해야 하므로 총 경우의 수는 9! 이다. (N!)

이는 대략 3.6 \* 10^5 이며 제한시간 내에 충분하다.

### 공간 복잡도

DFS를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N!)    |    O(1)     |

각 턴마다 타카하시와 아오키가 선택할 수 있는 경우의 수를 탐색한다.

이 때 타카하시가 얻는 점수는 양수로, 아오키가 얻는 점수는 음수로 더한다.

각 과정마다 두 사람의 점수 차이를 넘기므로 맨 마지막 좌표에서 점수 차이가 양수인지 음수인지 여부에 따라 승리자를 판단할 수 있다.

중간 과정에서 줄이 그어진 경우 현재 줄을 그은 사람이 승리하므로 이를 판단할 수 있다.

이를 이용해 현재 턴마다 다른 좌표에 돌을 놓아보며 자신이 승리할 수 있는 경우 가 존재하면 해당 좌표를 선택한다.

```cpp
int lines[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

string solution(vector<long long>& board) {
  int colors[9] = {0};

  // turn : +1 -> Takahashi, -1 -> Aoki
  function<long long(int, long long, int)> recursive =
      [&](int turn, long long point, int step) -> int {
    for (auto& line : lines) {
      if (colors[line[0]] == 0) continue;

      bool hasLine = colors[line[0]] == colors[line[1]] &&
                     colors[line[1]] == colors[line[2]];

      if (hasLine) {
        return colors[line[0]];
      }
    }

    if (step == 9) {
      if (point < 0) return -1;
      return +1;
    }

    for (int axis = 0; axis < 9; axis++) {
      if (colors[axis] != 0) continue;
      colors[axis] = turn;

      long long nextScore = point + turn * board[axis];
      if (recursive(-turn, nextScore, step + 1) == turn) {
        colors[axis] = 0;
        return turn;
      }

      colors[axis] = 0;
    }

    // lose case
    return -turn;
  };

  bool answer = recursive(1, 0, 0) == 1;
  return answer ? "Takahashi " : "Aoki ";
}
```

## 고생한 점
