# 472. Concatenated Words

[링크](https://leetcode.com/problems/concatenated-words/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 단어의 수를 N, 단어의 평균 길이를 L이라 하자.

각 단어에 대해 다른 단어들로 구성되는지 확인하는 데 최대 O(L^3)의 시간 복잡도를 사용한다.

동적 계획법을 사용할 경우 각 단어들을 미리 저장해놔야 하므로 단어를 순회하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 단어들을 저장하는 hash set에 O(N \* L)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     582      | O(N \* L^3) |  O(N \* L)  |

현재 만들고자 하는 단어를 S라 하자.

S는 다음과 같이 구성된다.

```javascript
const s = [...prefix, ...suffix];
```

여기서 맨 뒤에서부터 suffix를 증가시켯을 때 suffix가 단어 배열에 존재하고 prefix가 이전에 이미 구성되었던 경우 s는 생성 가능하다.

따라서 이를 이용해 각 단어마다 다른 단어들로 구성이 가능한지 판단한다.

이 때 prefix의 길이가 0인 경우는 정답에서 제외한다.

```cpp
bool wordBreak(string s, unordered_set<string>& wordSet) {
  int length = s.length();

  vector<bool> visited(length + 1, false);
  visited[0] = true;

  for (int right = 0; right < length; right++) {
    for (int left = right; left >= 0; left--) {
      int curLength = right - left + 1;
      if (curLength == length) break;
      string cur = s.substr(left, curLength);

      if (wordSet.count(cur) > 0 && visited[left]) {
        visited[right + 1] = true;
        break;
      }
    }
  }

  return visited[length];
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
  unordered_set<string> wordSet(words.begin(), words.end());

  vector<string> answer;
  for (string& w : words) {
    if (wordBreak(w, wordSet)) {
      answer.push_back(w);
    }
  }
  return answer;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     176      | O(N \* L^3) |  O(N \* L)  |

위 방법에서 탐색을 DFS로 변경한다.

```cpp
bool isConcatenate(string word, unordered_set<string>& wordSet) {
  for (int i = 1; i < word.length(); i++) {
    string prefix = word.substr(0, i);
    string suffix = word.substr(i, word.length() - i);

    if (wordSet.count(prefix) == 0) continue;
    if (wordSet.count(suffix) > 0 || isConcatenate(suffix, wordSet)) {
      return true;
    }
  }
  return false;
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
  unordered_set<string> wordSet(words.begin(), words.end());
  vector<string> ret;

  for (string& w : words) {
    if (isConcatenate(w, wordSet)) {
      ret.push_back(w);
    }
  }
  return ret;
}
```

## 고생한 점
