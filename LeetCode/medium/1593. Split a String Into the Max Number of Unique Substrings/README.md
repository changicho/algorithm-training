# 1593. Split a String Into the Max Number of Unique Substrings

[링크](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

각 경우마다 문자열을 나누는 경우의 수는 2^N 이다. 이 과정에서 현재 subString이 이전에 나왔는지 판단해야 한다. 이에 hash set을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

각 과정마다 백트래킹을 사용할 수 있다.

### 공간 복잡도

DFS로 탐색할 경우 call stack에 O(N)의 공간 복잡도가 필요하다. 이전에 방문한 subString을 판단하기 위해 hash set을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### DFS & backtracking

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      34      | O(N \* log_2(N)) |    O(N)     |

DFS로 탐색하며 현재 index에서 문자열을 나누는 경우와 그렇지 않은 경우를 탐색한다.

이 때 hash set에 이전에 방문한 subString을 저장하며, 이를 이용해 현재 subString이 이전에 나왔는지 판단한다.

만약 현재 남은 문자열의 길이와 방문한 subString의 길이가 현재 정답보다 작은 경우 탐색을 중지한다.

```cpp
int answer = 0;

void recursive(int i, string &s, string &temp, unordered_set<string> &visited) {
  if ((s.size() - i) + visited.size() < answer) return;

  if (s.size() == i) {
    answer = max(answer, (int)visited.size());
    return;
  }

  // keep
  temp.push_back(s[i]);
  recursive(i + 1, s, temp, visited);

  // cut
  if (temp.size() > 0 && visited.count(temp) == 0) {
    visited.insert(temp);

    string newTemp = "";
    recursive(i + 1, s, newTemp, visited);

    visited.erase(temp);
  }

  temp.pop_back();
}

int maxUniqueSplit(string s) {
  string temp = "";
  unordered_set<string> visited;

  recursive(0, s, temp, visited);

  return answer;
}
```

## 고생한 점
