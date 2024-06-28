# 1791. Find Center of Star Graph

[링크](www)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자.

입력받은 간선정보를 이용해 각 노드마다의 inDegree를 센다. 이를 이용해 중앙 노드를 찾을 수 있다.

이 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

inDegree들을 저장하는데 O(N)의 공간 복잡도가 필요하다.

### inDegree

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     133      |    O(N)     |    O(N)     |

중앙 노드의 inDegree는 N-1이다.

따라서 각 노드의 inDegree를 세다가 N-1이 되는 경우 해당 노드가 중앙 노드임을 알 수 있다.

```cpp
int findCenter(vector<vector<int>>& edges) {
  int n = edges.size() + 1;
  vector<int> inDegrees(n + 1);

  for (vector<int>& edge : edges) {
    inDegrees[edge[0]]++;
    inDegrees[edge[1]]++;

    if (inDegrees[edge[0]] == n - 1) return edge[0];
    if (inDegrees[edge[1]] == n - 1) return edge[1];
  }

  return -1;
}
```

## 고생한 점
