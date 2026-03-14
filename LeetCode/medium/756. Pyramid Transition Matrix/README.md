# 756. Pyramid Transition Matrix

[링크](https://leetcode.com/problems/pyramid-transition-matrix/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

알파벳의 갯수를 A, bottom의 길이를 N이라 하자.

가능한 방법들을 백트래킹과 메모이제이션을 통해 DFS로 탐색할 수 있다.

이에 O(A^N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 과정마다 다음 문자열을 생성하는데 O(N^2)의 공간 복잡도를 사용한다.

### DFS & 메모이제이션 & 백트래킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      58      |   O(A^N)    |   O(N^2)    |

현재 문자열에서 길이가 1 작은 다음 문자열을 생성하는 모든 방법들을 탐색하며, 길이가 1이 되는지 확인한다.

이 때 메모이제이션을 통해 이미 탐색한 문자열에 대해서는 다시 탐색하지 않도록 한다.

또한 현재 생성된 문자열에서 다음 단계로 생성이 불가능한 경우는 백트래킹을 통해 탐색하지 않는다.

```cpp
unordered_map<string, vector<char>> um;
unordered_map<string, bool> dp;

bool recursive(string& line) {
  int size = line.size();

  if (size == 1) return true;
  if (dp.count(line)) return dp[line];

  vector<vector<char>> ch(size - 1);

  for (int i = 0; i < size - 1; i++) {
    string key = {line[i], line[i + 1]};

    for (char& c : um[key]) {
      ch[i].push_back(c);
    }
  }

  unordered_set<string> us;

  function<void(int, string&)> dfs = [&](int i, string& cur) {
    if (i == size - 1) {
      us.insert(cur);
      return;
    }

    for (char& c : ch[i]) {
      if (cur.size() > 0) {
        string key = {cur.back(), c};
        if (um.count(key) == 0) continue;
      }

      cur.push_back(c);
      dfs(i + 1, cur);
      cur.pop_back();
    }
  };

  string cur = "";
  dfs(0, cur);

  bool ret = false;
  for (string next : us) {
    ret |= recursive(next);
    if (ret) break;
  }
  return dp[line] = ret;
}

bool pyramidTransition(string bottom, vector<string>& allowed) {
  for (string& s : allowed) {
    string key = {s[0], s[1]};
    char c = s[2];

    um[key].push_back(c);
  }

  return recursive(bottom);
}
```

## 고생한 점
