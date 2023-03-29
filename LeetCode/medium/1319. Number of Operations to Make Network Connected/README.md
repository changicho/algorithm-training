# 1319. Number of Operations to Make Network Connected

[링크](https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N, 간선의 갯수를 E라 하자.

간선의 갯수는 최소 N-1개 이상 되어야 모든 노드를 연결할 수 있다. 이를 우선 판단한다.

연결된 노드들 끼리 그룹으로 만들고 그룹의 갯수 - 1 개의 간선을 다른 그룹끼리 잇는데 사용할 수 있다.

이를 위헤 유니온 파인드를 사용한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

유니온 파인드에 O(N)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     107      |    O(N)     |    O(N)     |

간선의 갯수는 최소 N-1개 이상 되어야 모든 노드를 연결할 수 있다.

이것이 불가능한 경우 -1을 반환한다.

각 간선을 순회하며 두 노드를 연결한다.

이후 각 노드들이 연결된 독립된 그룹의 갯수를 센다.

이때 그룹의 갯수 - 1 만큼의 간선을 추가하면 모든 노드를 연결할 수 있다.

최소 간선의 조건은 만족했으며, 각 그룹마다 남는 간선이 존재하므로 해당 값을 구한다.

```cpp
vector<int> parents;
int parentsCount = 0;

int find(int node) {
  if (parents[node] == node) return node;
  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return;
  if (a > b) swap(a, b);
  parents[b] = a;
  parentsCount--;
}

int makeConnected(int n, vector<vector<int>>& connections) {
  if (connections.size() < n - 1) return -1;

  parents.resize(n);
  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }
  parentsCount = n;

  for (vector<int>& c : connections) {
    int a = c[0], b = c[1];

    merge(a, b);
  }

  return parentsCount - 1;
}
```

## 고생한 점
