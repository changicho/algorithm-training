# 425. Word Squares

[링크](https://leetcode.com/problems/word-squares/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

단어의 개수를 N, 단어들의 길이를 L이라 하자.

브루트 포스 방법으로 경우의 수를 구할 경우 경우를 생성하는 데 시간 복잡도는 O(N^L)이다.

이후 word square가 만족하는 지 검사하는데 L^2의 시간 복잡도를 사용한다. 따라서 완전 탐색의 경우 O(N^L \* L^2)의 시간 복잡도를 사용한다.

백트래킹을 사용해 원하는 경우만 탐색할 수 있다.

이 경우 해시맵과 트라이를 사용할 수 있다.

먼저 해시맵을 사용할 경우 각 단어들을 가능한 모든 prefix에 대해서 후보군으로 지정한다.

이 경우 후보군을 생성하는 데 O(N \* L)의 시간 복잡도가 소요된다.

이후 각 단어들을 탐색하면서 각 단어에 대해서 다음 index에 대해서 26번 탐색이 가능하다. (알파벳 소문자를 탐색하므로) 따라서 탐색하는 데 O(N \* 26^L)의 시간 복잡도를 사용한다.

트라이를 사용할 경우 탐색하는 과정에서 트라이에서 탐색을 진행하므로 O(L)의 시간 복잡도로 후보군을 탐색할 수 있다.

따라서 시간 복잡도는 O(N \* 26^L \* L)이다.

### 공간 복잡도

모든 prefix에 대해 결과적으로 N개의 단어를 저장한다.

hash map을 사용할 경우 모든 prefix에 대해서 저장해야 하므로 공간 복잡도는 O(N \* L)이다.

트라이를 사용할 경우 트라이의 공간 복잡도는 O(26^L)이다.

모든 prefix에 대해서 단어들을 저장하므로 O(N \* L)의 공간 복잡도를 사용한다.

### backtracking + hash map

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|     176      | O(N \* 26^L) |  O(N \* L)  |

모든 word에 대해서 가능한 prefix들에 현재 단어를 저장한다.

이 경우 prefix에 대해서 바로 가능한 후보군을 찾을 수 있다.

이후 재귀호출을 수행하며 가능한 후보군들만 탐색한다.

이 때 현재 후보군을 찾기 위해서 다음과 같은 방법을 사용한다.

- square에 저장된 단어의 수에 대해서, 다음에 추가할 단어의 prefix를 구한다.
- 크기가 s라고 했을 때, (s+1)번째 열에 대한 모든 문자를 더한걸 prefix로 사용한다.

이를 구현하면 다음과 같다.

```cpp
unordered_map<string, vector<string>> prefixMap;
vector<vector<string>> answer;

void recursive(vector<string> &square, int &limit) {
  int size = square.size();

  if (size == limit) {
    answer.push_back(square);
    return;
  }

  string target = "";
  for (int i = 0; i < size; i++) {
    target += square[i][size];
  }

  for (string &word : prefixMap[target]) {
    square.push_back(word);
    recursive(square, limit);
    square.pop_back();
  }
}

vector<vector<string>> wordSquares(vector<string> &words) {
  for (string &word : words) {
    string temp = "";
    prefixMap[temp].push_back(word);
    for (char &c : word) {
      temp += c;
      prefixMap[temp].push_back(word);
    }
  }
  int limit = words.front().length();

  vector<string> square;
  recursive(square, limit);

  return answer;
}
```

### backtracking + trie

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|     200      | O(N \* 26^L \* L) |  O(N \* L)  |

트라이를 다음과 같이 구현한다.

이 때 해당 단어에 대해서 후보군(vector)를 찾을 수 있도록 구현한다.

```cpp
class Trie {
 private:
  struct TrieNode {
    TrieNode *children[26] = {
        NULL,
    };
    bool isEnd;
    vector<string> words;

    TrieNode() { isEnd = false; }
  };

  TrieNode *root = new TrieNode;

 public:
  void insert(string word) {
    TrieNode *node = root;
    node->words.push_back(word);

    for (char &c : word) {
      if (!node->children[c - 'a']) {
        node->children[c - 'a'] = new TrieNode;
      }

      node = node->children[c - 'a'];
      node->words.push_back(word);
    }

    node->isEnd = true;
  }

  vector<string> startsWith(string prefix) {
    TrieNode *node = root;

    for (char &c : prefix) {
      if (!node->children[c - 'a']) {
        return {};
      }

      node = node->children[c - 'a'];
    }

    return node->words;
  }
};
```

backtracking + hash map을 이용했을 때와 동일한 방법으로 재귀호출을 통해 탐색을 진행한다.

이 때 후보군을 찾는 방법만 trie를 이용한 방법으로 변경한다.

```cpp
unordered_map<string, vector<string>> prefixMap;
vector<vector<string>> answer;
Trie trie;

void recursive(vector<string> &square, int &limit) {
  int size = square.size();

  if (size == limit) {
    answer.push_back(square);
    return;
  }

  string target = "";
  for (int i = 0; i < size; i++) {
    target += square[i][size];
  }

  vector<string> words = trie.startsWith(target);
  for (string &word : words) {
    square.push_back(word);
    recursive(square, limit);
    square.pop_back();
  }
}

vector<vector<string>> wordSquares(vector<string> &words) {
  for (string &word : words) {
    trie.insert(word);
  }
  int limit = words.front().length();

  vector<string> square;
  recursive(square, limit);

  return answer;
}
```

## 고생한 점
