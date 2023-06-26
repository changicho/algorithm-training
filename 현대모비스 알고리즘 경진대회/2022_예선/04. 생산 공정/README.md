# [현대모비스][예선] 생산 공정

[링크](https://level.goorm.io/exam/152117/%ED%98%84%EB%8C%80%EB%AA%A8%EB%B9%84%EC%8A%A4-%EC%98%88%EC%84%A0-%EC%83%9D%EC%82%B0-%EA%B3%B5%EC%A0%95/quiz/1)

## 설계

### 시간 복잡도

입력받은 단어의 수를 N, 쿼리의 수를 K라 하자. (단어의 길이는 최대 10)

각 단어들을 트라이에 저장하며 각 트라이 노드마다의 최선의 값을 갱신 후 쿼리를 수행할 수 있다.

이 경우 트라이에 저장하는데 O(N)의 시간 복잡도를, 쿼리를 수행하는데 O(K)의 시간 복잡돌르 사용한다.

현재 단어를 트라이에 저장하는데 L을 길이라 할 때 O(L)의 시간 복잡도를 사용한다. (알파벳의 종류는 26가지이므로 26 \* L만큼 탐색한다.)

따라서 총 시간 복잡도는 O(N + K)이다.

### 공간 복잡도

트라이에 저장되는 단어의 수는 N개 이므로 O(N)의 공간 복잡도를 사용한다.

(각 트라이 노드의 공간 복잡도는 O(26)이므로)

### 트라이

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N + K)   |    O(N)     |

단어의 알파벳 종류가 한정되어 있으므로 트라이를 사용할 수 있다.

이 때 각 트라이 노드는 다음과 같은 정보를 가진다.

- 현재 노드까지의 최선의 값
- 현재 노드까지의 최선의 값의 count
- 현재 단어
- 현재 단어의 count

단어를 트라이에 삽입할 때 다음 정보를 갱신해야 한다.

- 지나온 트라이 노느들에 대해 최선의 값
- 현재 트라이 노드의 count

이 때 이전에 갱신된 트라이 노드들에서 중간에 갱신되는 트라이 노드가 발생할 수 있으므로 이를 모두 고려해야 한다.

이에 대해서 최선의 값으로 매번 갱신한다.

이를 위해 트라이 노드에 삽입 시에 stack을 이용해 지나온 노드들을 저장 후 갱신한다.

```cpp
struct TrieNode {
  TrieNode *children[26] = {
      NULL,
  };

  string data;
  string maximum;
  int count;
  int maxCount;

  TrieNode() {
    data = "";
    count = 0;
    maximum = "";
    maxCount = 0;
  }
};

class Trie {
 private:
  TrieNode *root = new TrieNode;

 public:
  void insert(string word) {
    TrieNode *node = root;
    stack<TrieNode *> stk;

    for (char &c : word) {
      stk.push(node);

      if (!node->children[c - 'A']) {
        node->children[c - 'A'] = new TrieNode();
      }

      node = node->children[c - 'A'];
    }
    stk.push(node);

    node->count++;
    if (node->data == "") {
      node->data = word;
      node->maximum = word;
      node->maxCount = node->count;
    } else if (node->count == node->maxCount) {
      node->maximum = min(node->maximum, node->data);
    } else if (node->count > node->maxCount) {
      node->maximum = node->data;
      node->maxCount = node->count;
    }

    while (stk.size() > 0) {
      TrieNode *cur = stk.top();
      stk.pop();

      for (int i = 0; i < 26; i++) {
        TrieNode *child = cur->children[i];
        if (child == NULL) continue;

        if (cur->maxCount == child->maxCount) {
          cur->maximum = min(cur->maximum, child->maximum);
        } else if (cur->maxCount < child->maxCount) {
          cur->maximum = child->maximum;
          cur->maxCount = child->maxCount;
        }
      }
    }
  }

  TrieNode *search(string word) {
    TrieNode *node = root;

    for (char &c : word) {
      if (!node->children[c - 'A']) {
        return NULL;
      }

      node = node->children[c - 'A'];
    }

    return node;
  }
};

vector<string> solution(vector<string> &words, vector<string> &queries) {
  Trie trie;

  for (string &word : words) {
    trie.insert(word);
  }

  vector<string> ret;
  for (string &q : queries) {
    TrieNode *cur = trie.search(q);

    if (!cur) {
      ret.push_back("0");
    } else {
      string line = cur->maximum + " " + to_string(cur->maxCount);
      ret.push_back(line);
    }
  }
  return ret;
}
```

## 고생한 점

입력과 출력이 많으므로 빠른 입출력을 사용해야 한다.

현재 단어로 트라이 노드를 갱신할 때 지나온 트라이 노드들에 대해 모두 갱신 작업을 수행해야 한다.
