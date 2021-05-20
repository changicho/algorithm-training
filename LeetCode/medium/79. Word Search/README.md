# 79. Word Search

[링크](https://leetcode.com/problems/word-search/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

시작 좌표별로 탐색을 진행하는 완전 탐색을 진행해야한다.

이 때 정답이 될 수 없는 경우는 과감히 무시한다.

모든 좌표를 순회하는데 O(N \* M)의 시간복잡도가 필요하다.

또한 단어의 길이를 S라고 할 때 각 좌표마다 탐색을 이어가는데 좌표별로 4개의 방향이 가능하므로 O(S^4)의 시간 복잡도가 소요된다.

따라서 총 시간 복잡도는 O(N \* M \* S^4) 이다.

### 공간 복잡도

visited 여부를 체크하는데 별도의 공간을 사용할 수 있다.

이 경우 O(N \* M)의 공간 복잡도가 필요하다.

그러나 board의 문자는 upper_case, lower_case 두 경우밖에 없으므로 방문 여부를 board를 변환하며 표시할 수 있다.

이 경우 별도의 공간이 필요하지 않으므로 O(1)의 공간 복잡도가 필요하다.

### 백트래킹

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     136      | O(N \* M \* S^4) |    O(1)     |

매 경우마다 탐색을 이어나가면서 현재 word의 index 글자가 맞는지 조사한다.

이후 현재 좌표에서 시작했을 때 word를 만들 수 있는 경우를 판별한다.

```cpp
bool exist(vector<vector<char>>& board, string word) {
  rows = board.size();
  cols = board.front().size();

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (adjacentSearch(board, word, y, x, 0))
        return true;
    }
  }
  return false;
}

int rows;
int cols;
bool adjacentSearch(vector<vector<char>>& board, const string& word, int y, int x, int index) {
  if (index == word.size()) return true;
  if (y < 0 || x < 0 || y >= rows || x >= cols) return false;
  if (board[y][x] != word[index]) return false;

  board[y][x] = '*';
  bool furtherSearch = adjacentSearch(board, word, y + 1, x, index + 1) ||  // up
                        adjacentSearch(board, word, y - 1, x, index + 1) ||  // down
                        adjacentSearch(board, word, y, x - 1, index + 1) ||  // left
                        adjacentSearch(board, word, y, x + 1, index + 1);    // right

  board[y][x] = word[index];
  return furtherSearch;
}
```

## 고생한 점
