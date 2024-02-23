# 1245. Tree Diameter

[링크](https://leetcode.com/problems/tree-diameter/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 개수를 V, 간선의 갯수를 E라 하자.

간선을 순회하며 그래프를 생성해 사용해야 한다. 이에 O(E)의 시간 복잡도가 필요하다.

모든 경우를 탐색할 경우 O(V^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

재귀함수를 이용해 각 경우마다 반환값을 이용해 최대값을 갱신할 경우 시간 복잡도는 O(V)이다.

따라서 총 시간 복잡도는 O(V + E)이다.

### 공간 복잡도

그래프를 생성하는데 O(V + E)의 공간 복잡도가 필요하다.

재귀 호출을 이용할 경우 call stack에 최대 O(V)의 공간 복잡도가 필요하다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      29      |  O(V + E)   |  O(V + E)   |

각 노드를 재귀호출로 순회하며 다음과 같이 처리할 수 있다.

- 현재 노드의 자식노드들을 순회하며 각 노드부터 리프노드까지 최대 길이를 구한다.
- 자식 노드들 중 가장 긴 두개의 길이의 합이 정답의 후보가 될 수 있다.
- 자식 노드들 중 가장 긴 노드의 길이에 1을 더한 값이 현재 노드를 포함한 길이이다.

이를 이용해 각 노드마다 현재 노드가 끝점인 경우, 중간 경로에 포함된 경우 두 가지 최대 길이를 구한다.

```cpp
int answer = 0;

vector<vector<int>> graph;
vector<bool> visited;

int recursive(int node) {
  visited[node] = true;

  int first = -1, second = -1;

  for (int &next : graph[node]) {
    if (visited[next]) continue;

    int len = recursive(next);
    if (len >= first) {
      second = first;
      first = len;
    } else if (len > second) {
      second = len;
    }
  }

  if (first == -1) {
    answer = max(answer, 1);
    return 1;
  }

  if (second != -1) {
    int sum = first + second;
    answer = max(answer, sum);
  }

  return first + 1;
}

int treeDiameter(vector<vector<int>> &edges) {
  if (edges.size() == 0) return 0;

  int size = edges.size() + 1;
  graph.resize(size);
  visited.resize(size, false);

  for (vector<int> &e : edges) {
    int from = e[0], to = e[1];

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  recursive(0);

  return answer;
}
```

## 고생한 점
