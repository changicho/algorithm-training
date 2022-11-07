# 212. Word Search II

[링크](https://leetcode.com/problems/word-search-ii/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

행의 개수를 R, 열의 개수를 C라고 하자.

단어의 개수를 N, 단어의 최대 길이를 L이라 하자.

각 좌표들을 탐색하며 시작점으로 설정하고, 이를 이용해 다른 좌표들을 4방향으로 탐색하며 기존에 나온 단어인지 찾아봐야한다.

이를 빨리 검색하기 위해 트라이 구조를 사용한다.

트라이를 사용할 경우 단어를 검색하는데 O(L)의 시간 복잡도가 소요된다.

처음 단어를 트라이에 저장하는데 O(N \* L)의 시간복잡도를 사용한다.

각 좌표마다 시작점을 설정하는데 O(R \* C)의 시간 복잡도가, 하나의 시작 점에서 최대 탐색 가능한 경우의 수는 O(4^L)이다.

각 경우의 수마다 트라이에 포함하는지 탐색 하는데 O(L)의 시간 복잡도를 사용하므로

최종 시간 복잡도는 O(R \* C \* 4^L \* L)이 된다.

### 공간 복잡도

트라이 구조를 사용할 때 공간 복잡도는 O(26^L)이 된다.

해당 공간에 N개의 문자열을 저장하므로 O(N)의 공간 복잡도를 사용한다.

### 트라이

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|     131      | O(R \* C \* 4^L \* L) |    O(N)     |

우선 트라이에 모든 단어들을 저장한다.

이후 각 좌표별로 시작점을 설정하며 DFS로 단어들을 완성해간다.

이 때 현재 상태에서 탐색을 중지해야 하는 경우는 다음과 같다.

- 좌표가 범위를 벗어나는 경우
- 이미 방문한 좌표인경우
- 현재까지 string에 해당하는 prefix가 없는 경우

이 때 현재 탐색중인 단어가 트라이에 있는 경우 정답에 저장한다.

이후 트라이에서 해당 단어를 삭제한다. (중복을 피하기 위함)

삭제가 가능한 트라이는 다음과 같이 구현한다.

```cpp
// TireNode
class TrieNode {
  public:
  TrieNode* children[26] = {
      NULL,
  };
  bool isEnd = false;

  ~TrieNode() { delete *children; }
};

// Trie
class Trie {
  public:
  TrieNode* root;
  Trie(vector<string>& words) {
    root = new TrieNode();
    for (string& word : words) {
      insert(word);
    }
  }

  void insert(string& word) {
    TrieNode* cur = root;

    for (char& c : word) {
      int index = c - 'a';

      if (!cur->children[index]) {
        cur->children[index] = new TrieNode();
      }
      cur = cur->children[index];
    }

    cur->isEnd = true;
  }

  void erase(string word) { erase(word, 0, root); }

  private:
  void erase(string& word, int index, TrieNode* cur) {
    int length = word.length();

    if (index == length) {
      cur->isEnd = false;
      return;
    }

    int key = word[index] - 'a';

    erase(word, index + 1, cur->children[key]);

    // if children[key] is empty (there are no word after key)
    if (isEmpty(cur->children[key])) {
      cur->children[key] = NULL;
      delete cur->children[key];
    }
  }

  bool isEmpty(TrieNode* cur) {
    for (int i = 0; i < 26; ++i) {
      if (cur->children[i]) return false;
    }
    return true;
  }
};
```

기존 트라이에서 재귀호출로 끝 글자까지 탐색해 해당 key를 가지는 부분을 삭제하며, 역순으로 삭제할 수 있는 트라이노드들을 삭제한다.

이를 이용해 구현할 경우 다음과 같다.

```cpp
vector<string> answer;

void recursive(vector<vector<char>>& board, Axis axis, TrieNode* node, string& word, Trie& trie) {
  int rows = board.size();
  int cols = board.front().size();

  char cur = board[axis.y][axis.x];
  if (!node->children[cur - 'a']) return;

  word += cur;
  node = node->children[cur - 'a'];

  if (node->isEnd) {
    answer.push_back(word);
    trie.erase(word);
  }

  // visited check
  board[axis.y][axis.x] = ' ';

  for (Axis dir : dirs) {
    Axis next = {axis.y + dir.y, axis.x + dir.x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
      continue;
    if (board[next.y][next.x] == ' ') continue;
    if (!node->children[board[next.y][next.x] - 'a']) continue;

    recursive(board, next, node, word, trie);
  }

  board[axis.y][axis.x] = cur;

  word.pop_back();
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  int rows = board.size();
  int cols = board.front().size();

  Trie trie(words);
  TrieNode* root = trie.root;

  for (int y = 0; y < rows; ++y) {
    for (int x = 0; x < cols; ++x) {
      string word;
      recursive(board, {y, x}, root, word, trie);
    }
  }
  return answer;
}
```

## 고생한 점
