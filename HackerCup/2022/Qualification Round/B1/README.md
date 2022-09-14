# Problem B1: Second Friend

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2022/qualification-round/problems/B1)

| 난이도 |
| :----: |
|  9 pt  |

## 설계

### 시간 복잡도

격자의 행의 갯수를 R, 열의 갯수를 C라 하자.

정답 2차원 벡터를 생성하기 위해 O(R \* C)의 시간 복잡도를 사용한다.

정답은 아무것이나 가능하므로 그리디 알고리즘을 이용해 정답을 생성할 수 있다. 이 경우 O(R \* C)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(R \* C)이다.

### 공간 복잡도

정답 2차원 벡터를 생성하기 위해 O(R \* C)의 공간 복잡도를 사용한다.

### 브루트 포스

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(R \* C)  |  O(R \* C)  |

모든 좌표를 나무로 채운 경우 또한 정답이 될 수 있다.

행 또는 열의 갯수가 1인 경우는 모두 나무로 채워도 정답이 될 수 없으므로 이를 제외하고, 모두 나무로 채운 경우를 반환한다.

```cpp
vector<vector<char>> solution(int rows, int cols, vector<vector<char>> &board) {
  int treeCount = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '^') treeCount++;
    }
  }

  if (treeCount == 0) return board;
  if ((rows < 2 || cols < 2)) {
    return {};
  }

  vector<vector<char>> answer(rows, vector<char>(cols, '^'));

  return answer;
}
```

## 고생한 점
