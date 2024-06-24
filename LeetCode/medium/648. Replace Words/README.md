# 648. Replace Words

[링크](https://leetcode.com/problems/replace-words/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 dictionary의 크기를 N, dictionary의 단어의 평균 길이를 L, sentence의 길이를 M이라 하자.

각 단어들을 저장 후 sentence를 순회하며 각 단어들을 dictionary에 있는 단어들로 치환할 수 있는지 확인한다.

이를 위해 트라이를 사용할 경우 O(L)의 시간 복잡도로 각 단어들을 치환 가능하다.

따라서 총 시간 복잡도는 O(N \* L + M)이다.

### 공간 복잡도

트라이에 O(26^L)의 공간 복잡도가 필요하다.

정답 문자열에 O(M)의 공간 복잡도가 필요하다.

### 트라이

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      57      | O(N * L + M) | O(26^L + M) |

dictionary에 있는 단어들을 트라이에 저장한다.

이후 sentence를 공백을 기준으로 split한 후 각 단어들을 트라이에 존재하는 단어로 치환한다.

이 때 트라이에서 순회시 prefix로 존재하는 단어를 찾기 위해 다음과 같이 함수를 구현한다.

- 루트 노드부터 탐색을 진행하며, 중간에 isEnd 노드를 만난 경우 prefix를 반환

```cpp
struct TrieNode {
  TrieNode *children[26] = {NULL};
  bool isEnd = false;
};

struct Trie {
  TrieNode *root = new TrieNode();

  void insert(string &word) {
    TrieNode *cur = root;

    for (char &c : word) {
      if (cur->children[c - 'a'] == NULL) {
        cur->children[c - 'a'] = new TrieNode();
      }
      cur = cur->children[c - 'a'];
    }
    cur->isEnd = true;
  }

  string getPrefix(string &word) {
    string prefix = "";
    TrieNode *cur = root;
    for (char &c : word) {
      if (cur->isEnd) {
        return prefix;
      }
      prefix += c;

      if (cur->children[c - 'a'] == NULL) {
        return word;
      }
      cur = cur->children[c - 'a'];
    }
    return prefix;
  }
};

string replaceWords(vector<string> &dictionary, string sentence) {
  Trie trie;

  for (string &word : dictionary) {
    trie.insert(word);
  }

  string ret = "";
  istringstream ss(sentence);
  string word;
  while (getline(ss, word, ' ')) {
    ret += trie.getPrefix(word);

    ret += ' ';
  }

  ret.pop_back();
  return ret;
}
```

## 고생한 점
