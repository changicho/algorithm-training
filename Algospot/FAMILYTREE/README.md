# 족보 탐험

[링크](https://algospot.com/judge/problem/read/FAMILYTREE)

| 정답률(\_%) |
| :---------: |
|     23      |

## 설계

### 시간 복잡도

노드의 갯수를 N 이라 하자.

각 노드에 대한 LCA를 직접 구할 경우 각 경우마다 O(depth)의 시간 복잡도를 사용한다.

이는 O(N)이 가능하므로 최악의 경우 시간 복잡도는 O(N \* Q)이다.

각 노드를 preOrder로 방문한 경로를 세그먼트 트리를 이용해 LCA를 구할 수 있다.

이 경우 생성에 O(N)의 시간 복잡도를, 쿼리에 O(log_2(N))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N + Q \* log_2(N))이다.

### 공간 복잡도

세그먼트 트리를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

## 정리

각 트리의 노드의 번호를 다음과 같이 재구성한다.

- 부모 노드는 자식 노드보다 숫자가 무조건 작음

이 경우 부모 노드부터 모든 노드를 preOrder로 방문한 경로를 생성했을 때 (자기 자신으로 돌아오는 방문도 path에 추가), 두 노드 사이의 LCA는 해당 경로에서 두 노드 사이에 있는 최소 노드번호가 된다.

예를 들어 다음과 같은 방문 경로를 보자.

- 1, 2, 3, 2, 4, 5, 4, 2, 1, 6, 7, 8, 7, 1

5와 8의 LCA를 구하는 경우, 5가 등장하는 위치는 6번째이고, 7이 처음 등장하는 위치는 11번째, 13번째 이다.

등장하는 위치에 상관없이, 두 노드가 존재하는 경로 사이의 최소 값은 1이 된다.

- 1, 2, 3, 2, 4, **5, 4, 2, 1, 6, 7, 8, 7**, 1

따라서 이 경우 LCA는 1이 된다.

이를 위해 입력받은 노드의 번호를 새로 갱신해주고 preOrder를 순회하며 방문 경로를 생성한다.

이후 방문 경로에 대해 세그먼트 트리를 생성한다.

각 쿼리마다 LCA를 구한 뒤, LCA와 두 노드 사이의 거리 (depth)를 이용해 정답을 구한다.

- (노드 A의 depth) + (노드 B의 depth) - 2 \* (LCA의 depth)

```cpp
void solution() {
  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> graph(N);
  for (int node = 1; node < N; node++) {
    int parent;
    cin >> parent;

    graph[parent].push_back(node);
  }

  vector<int> visitPath;
  unordered_map<int, int> newIndex;
  vector<int> depths(N);

  preOrder(0, graph, visitPath, newIndex, 0, depths);

  unordered_map<int, int> newIndexReverse;
  for (auto &it : newIndex) {
    int key = it.first, val = it.second;
    newIndexReverse[val] = key;
  }

  vector<int> firstIndex(N, -1);
  for (int i = 0; i < visitPath.size(); i++) {
    int cur = visitPath[i];

    firstIndex[cur] = i;
  }

  SegmentTree<int> segment(visitPath);

  for (int i = 0; i < Q; i++) {
    int leftNode, rightNode;
    cin >> leftNode >> rightNode;

    int left = firstIndex[newIndex[leftNode]];
    int right = firstIndex[newIndex[rightNode]];

    if (left > right) swap(left, right);
    int LCA = newIndexReverse[segment.query(left, right)];

    int leftDepth = depths[leftNode] - depths[LCA];
    int rightDepth = depths[rightNode] - depths[LCA];

    cout << leftDepth + rightDepth << "\n";
  }
}
```

## 고생한 점
