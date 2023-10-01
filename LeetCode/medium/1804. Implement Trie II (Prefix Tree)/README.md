# 1804. Implement Trie II (Prefix Tree)

[링크](https://leetcode.com/problems/implement-trie-ii-prefix-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

단어의 최대 길이를 L, 단어의 갯수를 N이라 하자.

각 과정마다 삽입, 삭제, prefix count가 빈번하게 일어나므로 trie를 사용한다.

이 경우 각 연산당 시간 복잡도는 O(L)이다.

### 공간 복잡도

트라이를 사용할 경우 단어의 길이와 갯수에 영향을 받는다.

총 O(N * L)의 공간 복잡도를 사용한다.

### 트라이

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     149      |    O(L)     |  O(N * L)   |

삽입 연산 외에 prefix로 시작하는 갯수, 해당 단어의 수, 삭제 연산을 수행할 수 있다.

이 때 prefix로 시작하는 갯수는 삽입시 방문하는 각 노드마다의 count를 증가시키는 방법으로 구현할 수 있다.

해당 단어들이 중복되서 존재할 수 있으므로 단어마다 끝나는 노드에 해당 단어의 수를 증가시키는 방법으로 구현한다.

이 때 prefix count와 해당 단어가 존재하는 isEnd 변수로 구현할 경우 삭제시에 prefix로 count를 정확하게 판단할 수 없다.

```cpp
class Trie {
 private:
  struct TrieNode {
    TrieNode *children[26] = {
        NULL,
    };
    int count = 0;
    int endCount = 0;
  };

  TrieNode *root = new TrieNode();

 public:
  Trie() {}

  void insert(string word) {
    TrieNode *cur = root;
    for (char &c : word) {
      if (!cur->children[c - 'a']) {
        cur->children[c - 'a'] = new TrieNode();
      }
      cur = cur->children[c - 'a'];
      cur->count++;
    }
    cur->endCount++;
  }

  int countWordsEqualTo(string word) {
    TrieNode *cur = root;
    for (char &c : word) {
      if (!cur->children[c - 'a']) {
        return 0;
      }
      cur = cur->children[c - 'a'];
    }
    return cur->endCount;
  }

  int countWordsStartingWith(string prefix) {
    TrieNode *cur = root;
    for (char &c : prefix) {
      if (!cur->children[c - 'a']) {
        return 0;
      }
      cur = cur->children[c - 'a'];
    }
    return cur->count;
  }

  void erase(string word) {
    TrieNode *cur = root;
    for (char &c : word) {
      cur = cur->children[c - 'a'];
      cur->count--;
    }
    cur->endCount--;
  }
};
```

## 고생한 점
