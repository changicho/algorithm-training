# 79. Word Search

[링크](https://leetcode.com/problems/word-search/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C, 검색할 문자열의 갯수를 L이라 하자.

시작 좌표별로 탐색을 진행하는 완전 탐색을 진행해야한다.

이 때 정답이 될 수 없는 경우는 과감히 무시한다.

모든 좌표를 순회하는데 O(R \* C)의 시간복잡도가 필요하다.

또한 단어의 길이를 S라고 할 때 각 좌표마다 탐색을 이어가는데 좌표별로 3개의 방향이 가능하므로 O(3^L)의 시간 복잡도가 소요된다. (이전에 방문한 좌표를 제외)

따라서 총 시간 복잡도는 O(R \* C \* 3^L) 이다.

### 공간 복잡도

visited 여부를 체크하는데 별도의 공간을 사용할 수 있다.

이 경우 O(R \* C)의 공간 복잡도가 필요하다.

또한 DFS를 이용할 때 call stack에 O(L)의 공간 복잡도를 사용한다.

그러나 board의 문자는 upper_case, lower_case 두 경우밖에 없으므로 방문 여부를 board를 변환하며 표시할 수 있다.

이 경우 별도의 공간이 필요하지 않으므로 O(1)의 공간 복잡도가 필요하다.

### DFS & 백트래킹

| 내 코드 (ms) |   시간 복잡도    |  공간 복잡도  |
| :----------: | :--------------: | :-----------: |
|     136      | O(R \* C \* 3^L) | O(R \* C + L) |

매 경우마다 탐색을 이어나가면서 현재 word의 index 글자가 맞는지 조사한다.

이후 현재 좌표에서 시작했을 때 word를 만들 수 있는 경우를 판별한다.

입력받은 board 배열에 visited 체크를 구행할 경우 공간 복잡도는 call stack에만 사용되는 O(L)이 된다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool recursive(vector<vector<char>>& board, vector<vector<bool>>& visited,
                Axis axis, string& word, int index) {
  if (index == word.length()) return true;
  int rows = board.size(), cols = board.front().size();

  visited[axis.y][axis.x] = true;

  for (Axis dir : dirs) {
    Axis next = axis;
    next.y += dir.y;
    next.x += dir.x;

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
      continue;
    if (visited[next.y][next.x]) continue;
    if (board[next.y][next.x] != word[index]) continue;

    bool ret = recursive(board, visited, next, word, index + 1);

    if (ret) return true;
  }
  visited[axis.y][axis.x] = false;
  return false;
}

bool exist(vector<vector<char>>& board, string word) {
  int rows = board.size(), cols = board.front().size();

  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] != word.front()) continue;
      bool ret = recursive(board, visited, {y, x}, word, 1);

      if (ret) return true;
    }
  }

  return false;
}
```

## 고생한 점
