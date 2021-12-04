# 1048. Longest String Chain

[링크](https://leetcode.com/problems/longest-string-chain/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

단어의 개수를 N, 단어의 최대 길이를 L이라 하자.

하나의 단어에서 다른 단어로 만들 수 있는지 확인하는데 O(L^2)의 시간 복잡도를 사용한다. (substr을 이용)

DFS를 이용해 탐색하며 한 단어에서 시작해 다른 단어들로 이어갈수 있는 최대 갯수를 구한다고 하자.

이 경우 하나의 단어에서 다른 단어들을 선택하는 데 O(N!)의 시간 복잡도를 사용하며 각 경우마다 다른 단어로 이동하는 경우를 탐색하기 위해 O(L^2)의 시간 복잡도를 사용한다.

여기서 이미 방문한 단어에 대해서는 별도의 탐색을 진행하지 않도록 결과를 저장하는 memoization을 수행해야 한다.

이 경우 결국 단어들은 한번씩만 방문하므로 단어의 방문은 N번만 일어나며, 각 경우마다 substr를 이용해 새 단어를 만들고 이를 다음에 방문할 수 있는지 확인하므로 O(N \* L^2)의 시간 복잡도를 사용한다.

top-down방식을 확인했으니 bottom-up 방식의 동적 계획법을 사용할 경우를 살펴보자.

글자수가 작은 단어부터 시작해 다른 단어들을 만들어가야 하므로 우선 정렬을 수행한다. 이 연산에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 모든 단어를 순회하며 현재 단어를 만들 수 있는 이전의 단어를 모두 탐색한다.

이 경우에 단어 순회에 O(N), 다른 단어로 이동하는 경우에 O(L^2)의 시간 복잡도를 사용한다.

따라서 최종 시간 복잡도는 O(N \* (log_2(N) + L^2))가 된다.

### 공간 복잡도

DFS를 이용하는 memoization을 수행하는 경우 call stack에 O(N)의 공간 복잡도를 사용한다.

bottom-up방식을 사용하는 dp의 경우에 dp배열에 O(N)의 공간 복잡도를 사용한다.

### dynamic programming (top-down)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      64      | O(N \* L^2) |    O(N)     |

DFS & memoization (backtracking)을 사용한다.

현재 단어에서 predecessor인 길이가 짧은 다른 단어들을 만드는 방법은 다음과 같다.

```cpp
for (int i = 0; i < current.length(); i++) {
  string newWord = current.substr(0, i) + current.substr(i + 1);
}
```

이 방법을 이용해 DFS를 수행하며 현재 단어를 만들 수 있는 다른 단어들을 순서대로 탐색할 수 있다. (길이가 긴 순부터 짧은 순까지 탐색)

이를 모든 단어에 대해서 반복할 경우 가장 chain이 긴 경우를 찾을 수 있다.

여기서 단어의 방문이 중복될 수 있으므로 한 단어를 방문했을 때 결과를 dp에 저장해 재사용한다.

```cpp
unordered_map<string, int> memo;

int dfs(string current, unordered_set<string> &words) {
  if (memo.find(current) != memo.end()) return memo[current];

  int maxLength = 1;

  for (int i = 0; i < current.length(); i++) {
    string newWord = current.substr(0, i) + current.substr(i + 1);

    if (words.count(newWord) == 0) continue;

    int nextLength = dfs(newWord, words) + 1;
    maxLength = max(maxLength, nextLength);
  }

  return memo[current] = maxLength;
}

int longestStrChain(vector<string> &words) {
  int answer = 0;
  unordered_set<string> wordSet;

  for (string &word : words) {
    wordSet.insert(word);
  }

  for (string &word : words) {
    int length = dfs(word, wordSet);
    answer = max(answer, length);
  }

  return answer;
}
```

### dynamic programming (bottom-up)

| 내 코드 (ms) |       시간 복잡도        | 공간 복잡도 |
| :----------: | :----------------------: | :---------: |
|      64      | O(N \* (log_2(N) + L^2)) |    O(N)     |

단어의 길이가 짧은 순부터 현재 단어를 만들 수 있는 (길이가 짧은) 다른 단어들을 탐색한다.

길이가 짧은 순부터 순회하므로 현재 단어를 순회할 때 가능한 경우의 수를 이미 이전에 탐색했기 때문에 재사용 할 수 있다.

```cpp
int longestStrChain(vector<string> &words) {
  unordered_map<string, int> dp;

  sort(words.begin(), words.end(), [](string &word1, string &word2) {
    return word1.size() < word2.size();
  });

  int answer = 1;

  for (const string &word : words) {
    int length = word.length();
    int maximumLength = 1;

    for (int i = 0; i < length; i++) {
      string newWord = word.substr(0, i) + word.substr(i + 1, length + 1);

      if (dp.find(newWord) == dp.end()) continue;

      int previous = dp[newWord];
      maximumLength = max(maximumLength, previous + 1);
    }
    dp[word] = maximumLength;

    answer = max(answer, maximumLength);
  }

  return answer;
}
```

## 고생한 점
