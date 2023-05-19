# 1557. Minimum Number of Vertices to Reach All Nodes

[링크](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 노드의 갯수를 V, 간선의 갯수를 E라 하자.

그래프는 비순환 그래프이므로 사이클이 존재하지 않는다.

따라서 in degree가 0인 노드의 갯수를 세면 된다.

이 경우 각 간선과 노드의 순회에 O(V + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 노드의 진입차수를 저장하기 위해 O(V)의 공간 복잡도를 사용한다.

### 진입차수 계산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     297      |  O(V + E)   |    O(V)     |

간선은 방향이 존재한다.

각 노드에 대해서 간선의 진입 차수를 계산한다.

이 때 진입차수가 0인 노드의 경우 꼭 방문해야 해당 노드를 채울 수 있다.

이후 연결된 진입차수가 1 이상인 노드들은 다른 노드들을 방문하며 자연스럽게 방문할 수 있다.

따라서 진입차수가 0인 노드만 방문하면 된다.

```cpp
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
  int inDegree[100001] = {
      0,
  };

  for (vector<int>& e : edges) {
    int from = e[0], to = e[1];

    inDegree[to]++;
  }

  vector<int> answer;
  for (int node = 0; node < n; node++) {
    if (inDegree[node] == 0) {
      answer.push_back(node);
    }
  }

  return answer;
}
```

## 고생한 점
