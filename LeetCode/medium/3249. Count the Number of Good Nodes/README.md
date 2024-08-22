# 3249. Count the Number of Good Nodes

[링크](https://leetcode.com/problems/count-the-number-of-good-nodes/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

입력받은 간선 정보를 이용해 그래프를 생성한다. 이에 O(N)의 시간 복잡도가 소요된다.

이후 루트에서 부터 재귀호출로 탐색하며 각 노드의 자식 노드가 서브트리의 루트인 서브트리의 크기를 구한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀 호출에 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     731      |    O(N)     |    O(N)     |

루트 노드에서 부터 자식 노드들을 탐색한다.

이를 재귀호출로 탐색하며 해당 노드를 루트로 하는 서브트리의 크기를 반환한다.

이 때 자식들의 서브트리의 크기가 모두 같은 경우 해당 노드는 good node이며 정답을 증가시킨다.

```cpp
int answer = 0;

int recursive(int node, int parent, vector<vector<int>> &graph) {
  int ret = 0;

  int children = -1;
  bool isGood = true;
  for (int &next : graph[node]) {
    if (next == parent) continue;

    int result = recursive(next, node, graph);

    ret += result;
    if (children == -1) {
      children = result;
    } else if (children != result) {
      isGood = false;
    }
  }

  if (isGood) answer++;
  ret += 1;
  return ret;
}

int countGoodNodes(vector<vector<int>> &edges) {
  int size = edges.size() + 1;

  vector<vector<int>> graph(size);

  for (vector<int> &e : edges) {
    int from = e[0], to = e[1];
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  recursive(0, -1, graph);

  return answer;
}
```

## 고생한 점
