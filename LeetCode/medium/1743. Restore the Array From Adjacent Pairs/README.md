# 1743. Restore the Array From Adjacent Pairs

[링크](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

숫자의 갯수를 N이라 하자. adjacentPairs는 N-1 크기의 배열이다.

adjacentPairs를 순회하며 그래프를 생성하고 이어진 노드가 1개인 양 끝 노드 중 하나를 선택해 탐색을 진행해 정답을 구할 수 있다.

이 경우 그래프를 생성하는 데 최소 O(N)의 시간 복잡도를 사용한다. 이후 BFS 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 그래프를 생성할 경우 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     392      |    O(N)     |    O(N)     |

연결관계를 순회하며 그래프를 생성한다.

이 과정이 끝난 뒤 연결된 노드가 1개인 양 끝 노드를 발견할 수 있다.

해당 끝 노드중 하나를 시작점으로 삼고 탐색을 진행한다. 이 과정에서 탐색하는 순서대로 정답을 만들 수 있다.

```cpp
vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
  unordered_map<int, vector<int>> graph;

  for (vector<int> &pair : adjacentPairs) {
    int from = pair[0], to = pair[1];

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  int cur = -1;
  unordered_set<int> visited;

  for (auto it : graph) {
    if (it.second.size() == 1) {
      cur = it.first;
      break;
    }
  }

  vector<int> answer;
  while (visited.count(cur) == 0) {
    answer.push_back(cur);
    visited.insert(cur);

    for (int &next : graph[cur]) {
      if (visited.count(next) > 0) continue;

      cur = next;
      break;
    }
  }

  return answer;
}
```

## 고생한 점
