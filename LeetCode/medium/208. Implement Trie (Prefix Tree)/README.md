# 208. Implement Trie (Prefix Tree)

[링크](https://leetcode.com/problems/implement-trie-prefix-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

trie구조를 만들어야 한다.

W를 단어의 개수라고 하고, L을 단어의 길이라고 하자.

삽입과 검색을 진행하는 데 O(L)의 연산이 소요된다.

따라서 모든 단어들을 가지고 trie 구조를 만드는 데 O(W \* L)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 자리마다 노드를 가지며 해당 노드는 가능한 문자의 수 만큼의 자식 노드들을 가질 수 있다.

가능한 알파벳의 개수를 N라 하자. 이는 26개 이므로 (소문자만 사용)

따라서 공간 복잡도는 O(26^L)이다.

### 트라이

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      56      |  O(W \* L)  |   O(26^L)   |

각 단어의 자리별로 노드를 생성해 트라이를 생성한다.

트라이는 문자열을 효율적으로 저장하고 탐색할 수 있는 K진 트리의 자료구조이다.

원하는 문자열을 찾는 데 들어가는 시간 복잡도는 O(L)이다.

각 단계마다 문자열들을 key로 설정하고 이후 탐색을 진행하는 방식으로 탐색을 최적화한다.

이때 중복된 단계에서 문자열이 어떨때는 마지막 문자열일수도, 아닐수도 있기 때문에 boolean으로 이 단계가 끝인지 여부또한 저장한다.

루트 노드의 경우 key값이 없음에 유의한다.

TrieNode의 구현은 다음과 같다.

```cpp
// use array
struct TrieNode {
  // 모든 char에 대해 선언했으므로 문제에 주어진 26자에 대해서만 최적화도 가능하다
  struct TrieNode *children[256] = {
      NULL,
  };

  bool isEnd = false;
};

// use hashmap
struct TrieNode {
  unordered_map<char, TrieNode *> children;
  bool isEnd;

  TrieNode() { isEnd = false; }
};
```

이를 이용해 삽입과 검색, prefix검색을 다음과 같이 구현 가능하다.

```cpp
class Trie {
 private:
  struct TrieNode {
    unordered_map<char, TrieNode *> children;
    bool isEnd;

    TrieNode() { isEnd = false; }
  };

  TrieNode *root = new TrieNode;

 public:
  void insert(string word) {
    TrieNode *node = root;

    for (char c : word) {
      if (!node->children[c]) {
        node->children[c] = new TrieNode;
      }

      node = node->children[c];
    }

    node->isEnd = true;
  }

  bool search(string word) {
    TrieNode *node = root;

    for (char c : word) {
      if (!node->children[c]) {
        return false;
      }

      node = node->children[c];
    }

    return node && node->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode *node = root;

    for (char c : prefix) {
      if (!node->children[c]) {
        return false;
      }

      node = node->children[c];
    }

    return node;
  }
};
```

## 고생한 점
