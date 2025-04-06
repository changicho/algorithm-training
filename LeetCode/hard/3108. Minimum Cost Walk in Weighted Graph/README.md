# 3108. Minimum Cost Walk in Weighted Graph

[링크](https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

노드의 갯수를 N, 간선의 갯수를 E, 쿼리의 갯수를 Q라 하자.

각 노드들을 연결하며 그래프를 유니온 파인드로 구성할 수 있다.

각 그래프에 속한 노드들의 문제 조건에 따른 cost 비용은 동일하다.

따라서 유니온 파인드를 이용해 각 그래프마다의 cost를 구할 수 있다.

이에 O(N + E)의 시간 복잡도가 소요된다.

이후 정답을 생성하는데 O(Q)의 시간 복잡도가 소요된다.

따라서 최종 시간 복잡도는 O(N + E + Q)이다.

### 공간 복잡도

유니온 파인드에 O(N)의 공간 복잡도가 필요하다.

정답에 O(Q)의 공간 복잡도가 필요하다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      14      | O(N + E + Q) |  O(N + Q)   |

각 노드들이 연결되어 그래프를 구성한다고 하자.

각 노드들을 방문할 때마다 edge의 cost를 &연산하며 진행한다.

방문하는 정점이 많을 수록 많은 edge를 방문하며 &연산의 결과값은 작아질것이다.

따라서 각 그래프에 속한 노드들의 경우 최소값을 동일하게 만들 수 있다.

이를 이용해 유니온 파인드를 이용해 각 그래프의 cost를 구할 수 있다.

이후 query에 대해서는 두 노드가 같은 그래프에 속하는지 확인하고, 그래프의 cost를 반환한다.

```cpp
vector<int> parents;

int find(int node) {
  if (parents[node] == node) return node;
  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);

  if (a > b) swap(a, b);
  parents[b] = a;
}

vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query) {
  parents.resize(n + 1);
  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }

  // all bit mask
  vector<int> costs(n, INT_MAX);
  for (vector<int> &e : edges) {
    int a = e[0], b = e[1], c = e[2];

    merge(a, b);
  }
  for (vector<int> &e : edges) {
    int a = e[0], b = e[1], c = e[2];

    costs[find(a)] &= c;
  }

  vector<int> answer;
  for (vector<int> &q : query) {
    int a = q[0], b = q[1];

    if (find(a) != find(b)) {
      answer.push_back(-1);
    } else {
      answer.push_back(costs[find(a)]);
    }
  }
  return answer;
}
```

## 고생한 점
