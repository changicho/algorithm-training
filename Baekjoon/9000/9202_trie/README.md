# 9202. Boggle

[링크](https://www.acmicpc.net/problem/9202)

|   난이도   | 정답률(\_%) | 시간 제한(초) |
| :--------: | :---------: | :-----------: |
| 플래티넘 V |   25.172    |      10       |

## 설계

### 시간 복잡도

단어의 수 W는 최대 300,000, 단어의 길이 L은 최대 8, 보드의 개수는 최대 30 이다.

보드의 행의 개수 R, 열의 개수 C는 모두 4 이다.

트라이를 이용할 경우 단어 삽입에 O(L)의 시간 복잡도가 소요되므로 모든 단어를 트라이에 삽입하는 데 O(W \* L)의 시간 복잡도가 소요된다.

이는 최악의 경우 O(300,000 \* 8) 이다. O(2,400,000);

이후 모든 좌표에 대해서 탐색을 진행한다고 하자.

하나의 좌표에서 시작했을 때 탐색의 가지수는 최대 O(8^L)이 된다. (8방향, 단어의 길이만큼)

이를 모든 좌표에 대해서 반복해야 하므로 하나의 보드에서 들어가는 시간 복잡도는 O(16 \* 8^L)이다.

이는 최악의 경우 O(16 \* 16777216)이다. O(268,435,456)

이는 제한시간 10초 내에 충분하다.

### 공간 복잡도

트라이를 생성할 경우 가능한 글자의 가지수를 N이라고 할 때 O(N^L)만큼의 공간이 필요하다.

이는 최악의 경우 O(26^8)이다. O(208,827,064,576)

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     4180     |      228       |

트라이를 사용해 모든 단어를 미리 저장한다.

이후 보드를 입력받으며 보드의 모든 좌표를 순회하며, 해당 좌표를 시작점으로 DFS를 통해 트라이에 존재하는 지 판별한다.

이 때 현재 상태에서 탐색을 중지해야 하는 경우는 다음과 같다.

- 좌표가 범위를 벗어나는 경우
- 이미 방문한 좌표인경우
- 현재까지 string에 해당하는 prefix가 없는 경우

현재 탐색중인 단어가 트라이에 있는 경우 정답에 저장한다.

모든 좌표에 대한 탐색 이후 정답의 점수와, 가장 긴 트라이를 구한다.

```cpp
class Trie {
 private:
  struct TrieNode {
    TrieNode* children[26] = {
        NULL,
    };
    bool isEnd = false;
  };

  TrieNode* root = new TrieNode;

 public:
  Trie() {}

  void insert(string& word) {
    TrieNode* cur = root;

    for (char& c : word) {
      if (cur->children[c - 'A'] == NULL) {
        cur->children[c - 'A'] = new TrieNode;
      }
      cur = cur->children[c - 'A'];
    }

    cur->isEnd = true;
  }

  bool search(string word) {
    TrieNode* cur = root;

    for (char& c : word) {
      if (cur->children[c - 'A'] == NULL) {
        return false;
      }
      cur = cur->children[c - 'A'];
    }

    return cur->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode* cur = root;

    for (char& c : prefix) {
      if (cur->children[c - 'A'] == NULL) {
        return false;
      }
      cur = cur->children[c - 'A'];
    }
    return true;
  }
};
```

```cpp
struct Axis {
  int y, x;
};

Axis dirs[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int scores[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

void recursive(string board[4], Axis axis, string& path, Trie& trie,
               unordered_set<string>& answers) {
  char cur = board[axis.y][axis.x];
  if (cur == '*') return;
  if (!trie.startsWith(path)) return;

  path += cur;
  if (trie.search(path)) answers.insert(path);

  // visited check
  board[axis.y][axis.x] = '*';
  for (Axis dir : dirs) {
    Axis next = {axis.y + dir.y, axis.x + dir.x};

    if (next.y < 0 || next.y >= 4 || next.x < 0 || next.x >= 4) continue;
    if (board[next.y][next.x] == '*') continue;

    recursive(board, next, path, trie, answers);
  }
  board[axis.y][axis.x] = cur;
  path.pop_back();
}

void solution() {
  int W, B;
  cin >> W;

  vector<string> words(W);
  for (int i = 0; i < W; i++) {
    cin >> words[i];
  }

  Trie trie;
  for (string& word : words) {
    trie.insert(word);
  }

  string board[4] = {};

  cin >> B;
  while (B--) {
    for (int y = 0; y < 4; y++) {
      cin >> board[y];
    }

    unordered_set<string> answers;

    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        string path;
        recursive(board, {y, x}, path, trie, answers);
      }
    }

    string longest = "";
    int score = 0;
    for (string cur : answers) {
      score += scores[cur.length()];
      if (longest.length() < cur.length() ||
          longest.length() == cur.length() && cur < longest) {
        longest = cur;
      }
    }

    cout << score << " " << longest << " " << answers.size() << "\n";
  }
}
```

## 고생한 점
