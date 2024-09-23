# 1858. Longest Word With All Prefixes

[링크](https://leetcode.com/problems/longest-word-with-all-prefixes/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 words의 크기를 N, 각 문자열의 길이의 합을 L이라 하자.

트라이를 사용해 각 단어의 접두사들이 모두 존재하는지 판단할 수 있다.

이 경우 O(N \* L)의 시간 복잡도가 소요된다.

hash set을 이용해 각 단어의 접두사들을 저장할 경우 O(N \* L)의 시간 복잡도가 소요된다.

정렬을 이용한 hash set을 사용할 경우 O(N \* log_2(N) \* L)의 시간 복잡도가 소요된다.

### 공간 복잡도

hash set을 이용해 각 단어의 접두사들을 저장할 경우 O(N \* L)의 공간 복잡도가 필요하다.

트라이를 사용할 경우 O(N \* L)의 공간 복잡도가 필요하다.

### 트라이

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     107      |  O(N \* L)  |  O(N \* L)  |

트라이에 모든 단어를 저장한 뒤, 각 단어들의 prefix들이 모두 트라이에 존재하는지 판단한다.

```cpp
struct TrieNode {
  bool isEnd = false;
  TrieNode *children[26] = {NULL};
};

string answer = "";
TrieNode *root = new TrieNode();

void insert(string &s) {
  TrieNode *cur = root;

  for (char &c : s) {
    if (cur->children[c - 'a'] == NULL) {
      cur->children[c - 'a'] = new TrieNode();
    }

    cur = cur->children[c - 'a'];
  }

  cur->isEnd = true;
}

void isPrefix(string &s) {
  TrieNode *cur = root;
  bool isPrefix = true;

  for (char &c : s) {
    cur = cur->children[c - 'a'];
    isPrefix &= cur->isEnd;
  }

  if (isPrefix) {
    if (answer.size() < s.size()) {
      answer = s;
    } else if (answer.size() == s.size()) {
      answer = min(answer, s);
    }
  }
}

string longestWord(vector<string> &words) {
  int size = words.size();

  for (string &word : words) {
    insert(word);
  }

  for (string &word : words) {
    isPrefix(word);
  }

  return answer;
}
```

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     162      |  O(N \* L)  |  O(N \* L)  |

hash set에 모든 단어를 저정한다.

이후 각 단어들의 prefix가 모두 hash set에 존재하는지 판단한다.

```cpp
string longestWord(vector<string> &words) {
  unordered_set<string> us(words.begin(), words.end());

  int size = words.size();

  string answer = "";

  for (string &word : words) {
    bool isPrefix = true;

    string path = "";
    for (char &c : word) {
      path += c;

      isPrefix &= us.count(path) > 0;

      if (!isPrefix) break;
    }

    if (isPrefix) {
      if (answer.size() < word.size()) {
        answer = word;
      } else if (answer.size() == word.size()) {
        answer = min(answer, word);
      }
    }
  }

  return answer;
}
```

### hash set & sort

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|      92      | O(N \* log_2(N) \* L) |  O(N \* L)  |

각 단어들을 오름차순으로 정렬한다.

이 경우 각 단어의 prefix들은 현재 단어의 앞에 존재한다.

prefix들을 hash set에 저장하며, 현재 단어의 맨 뒷글자를 제거한 prefix가 hash set에 존재하는지 판단한다.

존재하는 경우 현재 단어를 hash set에 추가한다.

이후 hash set의 단어 중 정답을 찾는다.

```cpp
string longestWord(vector<string> &words) {
  sort(words.begin(), words.end());
  unordered_set<string> validSet;
  validSet.insert("");

  int size = words.size();

  string answer = "";

  for (string &word : words) {
    char back = word.back();
    word.pop_back();

    if (validSet.count(word)) {
      word.push_back(back);
      validSet.insert(word);
    } else {
      word.push_back(back);
    }

    if (validSet.count(word)) {
      if (answer.size() < word.size()) {
        answer = word;
      } else if (answer.size() == word.size()) {
        answer = min(answer, word);
      }
    }
  }

  return answer;
}
```

## 고생한 점
