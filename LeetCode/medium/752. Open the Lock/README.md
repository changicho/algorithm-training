# 752. Open the Lock

[링크](https://leetcode.com/problems/open-the-lock/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

가능한 총 경우의 수는 0000 ~ 9999 이므로 10000가지 이다.

이를 BFS로 탐색할 경우 시간 복잡도는 O(10000) 이므로 제한시간 내에 충분하다.

### 공간 복잡도

BFS에 방문배열을 사용할 경우 O(10000)의 공간 복잡도가 필요하다.

### BFS with step

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     146      |  O(10000)   |  O(10000)   |

단계별 BFS를 사용해 탐색한다.

```cpp
int openLock(vector<string>& deadends, string target) {
  unordered_set<string> deadSet(deadends.begin(), deadends.end());
  unordered_set<string> visited;

  queue<string> q;
  if (deadSet.count("0000") == 0) q.push("0000");

  int step = 0;
  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      string cur = q.front();
      q.pop();

      visited.insert(cur);

      if (cur == target) return step;

      for (int i = 0; i < 4; i++) {
        string next = cur;
        next[i] = (next[i] == '9') ? '0' : next[i] + 1;
        if (visited.count(next) == 0 && deadSet.count(next) == 0) {
          visited.insert(next);
          q.push(next);
        }

        next = cur;
        next[i] = (next[i] == '0') ? '9' : next[i] - 1;
        if (visited.count(next) == 0 && deadSet.count(next) == 0) {
          visited.insert(next);
          q.push(next);
        }
      }
    }

    step++;
  }

  return -1;
}
```

## 고생한 점
