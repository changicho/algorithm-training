# 582. Kill Process

[링크](https://leetcode.com/problems/kill-process/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

process의 수를 N이라 하자.

루트 부터 시작해서 DFS를 이용해 탐색하며 삭제하는 process들을 탐색한다.

이에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

DFS에 O(N)의 공간 복잡도가 소요된다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      73      |    O(N)     |    O(N)     |

pid, ppid 정보를 이용해 각 노드마다 자식 노드들을 저장한다.

이후 DFS로 탐색하며 kill할 노드를 탐색하며, kill할 노드가 발견되면 그 이후로 탐색하는 노드들은 모두 kill할 노드이므로 answer에 추가한다.

```cpp
unordered_map<int, vector<int>> children;

vector<int> answer;

void dfs(int node, bool isKill, int kill) {
  if (kill == node) {
    isKill = true;
  }
  if (isKill) answer.push_back(node);

  for (int& next : children[node]) {
    dfs(next, isKill, kill);
  }
}

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
  int size = pid.size();

  int start = -1;
  for (int i = 0; i < size; i++) {
    int c = pid[i];
    int p = ppid[i];

    if (p == 0) {
      start = c;
    } else {
      children[p].push_back(c);
    }
  }

  dfs(start, false, kill);
  return answer;
}
```

## 고생한 점
