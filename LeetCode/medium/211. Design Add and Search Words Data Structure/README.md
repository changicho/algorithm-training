# 211. Design Add and Search Words Data Structure

[링크](https://leetcode.com/problems/design-add-and-search-words-data-structure/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

단어의 갯수를 N, 단어의 길이를 L이라 하자. (N <= 10^4, L <= 25)

각 단어마다 '.'가 포함되어있으며, 이는 모든 글자로 치환이 가능하다. (최대 3개)

따라서 최대 각 단어마다 최대 26^3가지 경우를 탐색할 수 있다. 이 중 단어의 갯수만큼 최대 탐색이 가능하므로 min(26^3, N)가지 경우를 탐색한다.

이를 hash set으로 관리하고 모두 탐색할 경우 제한시간 내에 불가능하다.

각 연산마다 트라이를 이용해 치환 가능한 경우마다 탐색을 이어나갈 수 있다.

이 경우 삽입에 O(L), 확인에 최대 O(L \* min(26^3, N))의 시간 복잡도를 사용한다.

### 공간 복잡도

트라이에 O(26^L)의 공간 복잡도를 사용한다.

재귀호출로 트라이를 탐색할 경우 O(L)의 공간 복잡도가 필요하다.

### 트라이

| 내 코드 (ms) |        시간 복잡도         | 공간 복잡도 |
| :----------: | :------------------------: | :---------: |
|     868      | O(L), O(L \* min(26^3, N)) | O(L + 26^L) |

입력받은 단어들을 트라이에 삽입한다.

특정 단어를 검색할 때, '.'가 포함되어 있는 경우에는 가능한 모든 알파뱃으로 치환하고 탐색을 이어나간다.

이 때 트라이에 삽입되지 않은 경우는 정답이 아니므로 탐색을 중단한다.

이는 트라이에 삽입되지 않은 단어(prefix)는 검색이 불가능하므로 백트래킹이 가능하다.

이를 위해 재귀호출로 탐색을 진행하며 불가능한 경우는 건너뛴다.

```cpp
class WordDictionary {
  struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
  };

  TrieNode* root = new TrieNode();

  bool recursive(int index, string& word, TrieNode* node) {
    int size = word.size();

    if (index == size) {
      return node->isEnd;
    }

    if (word[index] != '.') {
      char c = word[index];
      if (node->children[c - 'a'] == NULL) return false;
      bool ret = recursive(index + 1, word, node->children[c - 'a']);

      return ret;
    }

    for (char c = 'a'; c <= 'z'; c++) {
      if (node->children[c - 'a'] == NULL) continue;

      bool ret = recursive(index + 1, word, node->children[c - 'a']);

      if (ret) return true;
    }
    return false;
  }

 public:
  WordDictionary() {}

  void addWord(string word) {
    TrieNode* cur = root;
    for (char& c : word) {
      if (cur->children[c - 'a'] == NULL)
        cur->children[c - 'a'] = new TrieNode();

      cur = cur->children[c - 'a'];
    }
    cur->isEnd = true;
  }

  bool search(string word) {
    TrieNode* cur = root;
    return recursive(0, word, cur);
  }
};
```

## 고생한 점
