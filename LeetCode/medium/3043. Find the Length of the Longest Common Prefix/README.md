# 3043. Find the Length of the Longest Common Prefix

[링크](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

각 수의 최대 값은 10^8 이다. 이 경우 수마다 prefix를 구하는 데 O(log_10(10^8))의 시간 복잡도가 필요하다. 이는 O(1)이다.

각 수마다 prefix를 모두 hash set에 저장 후 정답을 구할 수 있다. 이 경우 O(N + M)의 시간 복잡도를 사용한다.

trie를 사용할 경우 O(N + M)의 시간 복잡도가 필요하다.

### 공간 복잡도

hash set을 이용할 경우 O(N)의 공간 복잡도가 필요하다.

trie를 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 트라이

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     242      |  O(N + M)   |    O(N)     |

두 배열중 크기가 작은 배열을 기준으로 trie를 생성한다.

트라이에 모든 수의 prefix를 저장한 뒤, 다른 배열의 수를 순회하며 prefix가 존재하는지 확인한다.

```cpp
struct TrieNode {
  bool isEnd = false;
  TrieNode *children[10] = {
      0,
  };
};
int answer = 0;
TrieNode *root = new TrieNode();

void insert(int num) {
  string line = to_string(num);

  TrieNode *cur = root;
  for (char &c : line) {
    if (cur->children[c - '0'] == NULL) {
      cur->children[c - '0'] = new TrieNode();
    }
    cur = cur->children[c - '0'];
  }
  cur->isEnd = true;
}

void check(int num) {
  string line = to_string(num);
  int count = 0;

  TrieNode *cur = root;
  for (char &c : line) {
    if (cur->children[c - '0'] == NULL) break;
    count++;

    cur = cur->children[c - '0'];
  }

  answer = max(answer, count);
}

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
  if (arr1.size() > arr2.size()) swap(arr1, arr2);

  for (int &num : arr1) {
    insert(num);
  }

  for (int &num : arr2) {
    check(num);
  }
  return answer;
}
```

## 고생한 점
