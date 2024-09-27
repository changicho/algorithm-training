# 2416. Sum of Prefix Scores of Strings

[링크](https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 words의 크기를 N, 각 단어의 평균 길이를 L이라 하자.

트라이를 이용해 각 prefix들을 count 한 뒤 정답을 구할 수 있다.

이 경우 트라이에 삽입하는데 O(N \* L), 조회에 O(N \* L)의 시간 복잡도가 필요하다.

### 공간 복잡도

트라이에 O(N \* L)의 공간 복잡도가 필요하다.

### 트라이

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     561      |  O(N \* L)  |  O(N \* L)  |

트라이에 각 단어들을 삽입하며 해당 트라이 노드를 지나는 횟수를 count한다.

이후 각 단어에 대해 트라이에서 prefix들의 count의 합을 구한다.

```cpp
struct TrieNode {
  int count = 0;
  bool isEnd = false;
  TrieNode *children[26] = {NULL};
};

TrieNode *root = new TrieNode();

void insert(string &word) {
  TrieNode *cur = root;
  int sum = 0;
  for (char &c : word) {
    if (cur->children[c - 'a'] == NULL) {
      cur->children[c - 'a'] = new TrieNode();
    }

    cur = cur->children[c - 'a'];
    cur->count++;
    sum += cur->count;
  }
  cur->isEnd = true;
}

int query(string &word) {
  TrieNode *cur = root;
  int sum = 0;
  for (char &c : word) {
    cur = cur->children[c - 'a'];

    sum += cur->count;
  }
  return sum;
}

vector<int> sumPrefixScores(vector<string> &words) {
  int size = words.size();
  vector<int> answer(size, 0);

  for (string &word : words) {
    insert(word);
  }
  for (int i = 0; i < size; i++) {
    answer[i] = query(words[i]);
  }
  return answer;
}
```

## 고생한 점
