# 139. Word Break

[링크](https://leetcode.com/problems/word-break/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자. (최대 300)

패턴의 개수는 최대 1000개 까지이다. 이를 빨리 찾기 위해 hash set을 이용한다.

문자열의 index를 탐색하며 작은 단어들로 나눌 수 있다. 이를 재귀호출로 구현할 경우 시간 복잡도는 최악의 경우 O(2^N)까지 된다.

(각 index별로 나눌지 안나눌지)

이는 이전에 탐색한 index에서도 탐색을 진행할 수 있으므로 backtracking을 이용해 최적화를 진행할 수 있다.

이 경우 이전에 탐색했던 중복된 곳에서의 탐색은 일어나지 않으므로 시간 복잡도를 줄일 수 있다.

또는 위와 같은 아이디어를 이용해 중복을 줄이는 동적 계획법을 이용해 풀이할 수 있다.

이 경우 index마다 도달 가능한지 여부를 체크하고, 각 index마다 이전위치에서 현재 도달 가능한지를 확인한다.

이 경우 outer 탐새에 시간 복잡도는 O(N^2)이다.

내부적으로는 substring이 wordDict에 있는지 검사해야 하며 이는 O(N)의 시간 복잡도가 소요된다.

혹은 이를 뒤집어 저장하고 탐색할 경우 이전 subString을 이용할 수 있으므로 O(1)의 시간 복잡도로 탐색할 수 있다.

### 공간 복잡도

동적 계획법을 사용할 때 N크기만큼의 공간 복잡도가 필요하다. 따라서 공간 복잡도는 O(N)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(N^2)    |    O(N)     |

모든 경우를 탐색하지 않고, index를 0부터 순회한다.

index의 의미는 index + 1길이 만큼의 문장을 주어진 wordDict의 단어들로 쪼갤 수 있는지 여부를 나타내는데 사용한다. 따라서 dp의 의미는 다음과 같다.

```cpp
bool visited[index]; // index길이 만큼의 문장을 만들 수 있는지
```

초기값은 다음과 같다.

```cpp
visited[0] = true; // 길이가 0인 문장은 기본적으로 생성됨
```

일반식은 다음과 같다. (현재 index에서 주어진 문장을 만들 수 있는지)

```cpp
// 현재 index = right라고 할 때
for (int left = right; left >= 0; left--) {
  int length = right - left + 1;
  string key = s.substr(left, length);

  if (wordSet.find(cur) != wordSet.end() && visited[left]) {
    visited[right + 1] = true;
    break;
  }
}
```

여기서 substr을 사용할 때 시간복잡도가 소요되며, left를 탐색할 때 이전에 사용한 문자열에서 맨 앞자리가 추가되는 방식이다.

이를 최적화 하기 위해 wordDict의 단어들을 뒤집어 저장하고, key를 생성할 때 문자열의 뒤에 문자를 추가하는 방식으로 탐색하면 시간복잡도와 공간복잡도를 절약할 수 있다.

```cpp
bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<string> wordSet;
  int length = s.length();

  int maxWordLength = 0;
  for (string word : wordDict) {
    reverse(word.begin(), word.end());
    maxWordLength = max(maxWordLength, (int)word.length());
    wordSet.insert(word);
  }

  vector<bool> visited(length + 1, false);
  visited[0] = true;

  for (int right = 0; right < length; right++) {
    string cur = "";

    int limit = max(0, right - maxWordLength);
    for (int left = right; left >= limit; left--) {
      cur += s[left];

      if (wordSet.find(cur) != wordSet.end() && visited[left]) {
        visited[right + 1] = true;
        break;
      }
    }
  }

  return visited[length];
}
```

### 백트래킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     120      |   O(2^N)    |    O(N)     |

재귀호출을 이용하며 백트래킹을 사용해 문제를 풀이할 수 있다.

```cpp
bool wordBreak(string s, vector<string>& wordDict) {
  int length = s.length();
  unordered_set<string> wordSet;

  vector<bool> visited(length + 1, false);
  for (string word : wordDict) {
    wordSet.insert(word);
  }

  for (string word1 : wordDict) {
    for (string word2 : wordDict) {
      string target = word1 + word2;

      if (wordSet.find(target) != wordSet.end()) wordSet.erase(target);
    }
  }

  recursive(0, s, wordSet, visited);

  return visited[length];
}

void recursive(int index, string& s, unordered_set<string>& wordSet, vector<bool>& visited) {
  int length = s.length();
  visited[index] = true;

  string temp = "";
  for (int i = index; i < length; i++) {
    temp += s[i];

    if (wordSet.find(temp) != wordSet.end() && !visited[i + 1]) {
      recursive(i + 1, s, wordSet, visited);
    }
  }
}
```

## 고생한 점
