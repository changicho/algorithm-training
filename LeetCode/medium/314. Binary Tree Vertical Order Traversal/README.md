# 314. Binary Tree Vertical Order Traversal

[링크](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 개수를 N이라 하자.

우선 모든 노드를 순회하며 값을 벡터에 넣어야한다.

이 때 각 값들이 원하는 순서로 들어가게 하기 위해 다음 2가지 방법을 사용한다.

1. 탐색 순서를 조절한다.
2. 탐색 결과를 정렬한다.

vertical로 값을 묶기 위해 map을 사용할 수 있다. 이 경우 map에 key로 값을 찾는 데 들어가는 시간 복잡도는 최대 O(N)이다.

순회하며 같은 vertical에서 그 값을 높이순으로 정렬해야 한다.

BFS로 높이순으로 탐색하며 별도의 정렬을 진행하지 않아도 된다. 이 경우 시간 복잡도는 O(N \* log_2(N))이다.

혹은 DFS등으로 순회 후에 값들을 정렬할 수 있다.

이 경우도 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

모든 값이 결국 새로운 2차원 백터에 저장되므로 O(N)의 공간 복잡도를 사용한다.

### BFS & map

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      8       | (N \* log_2(N)) |    O(N)     |

BFS를 진행하며 현재의 vertical을 같이 넘긴다.

map에 vertical을 key로, array을 value로 설정한다.

BFS로 순회하며 자동적으로 array에는 높이순으로 값이 정렬된다.

이후 map에 저장된 값들을 첫번째 iterator부터 순회해 정답 배열로 변환한다.

```cpp
vector<vector<int>> verticalOrder(TreeNode *root) {
  map<int, vector<int>> m;
  vector<vector<int>> ret;
  if (!root) return ret;

  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  while (!q.empty()) {
    pair<TreeNode *, int> cur = q.front();
    q.pop();

    TreeNode *node = cur.first;
    int index = cur.second;

    m[index].emplace_back(node->val);

    if (node->left) q.push({node->left, index - 1});
    if (node->right) q.push({node->right, index + 1});
  }

  for (auto &it : m) {
    ret.push_back(it.second);
  }
  return ret;
}
```

### BFS & hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |     (N)     |    O(N)     |

hash map을 사용해 vertical을 key로, array를 value로 설정한다.

이후 vertical의 범위에 대해 순차적으로 순회하며 정답 배열로 변환한다.

```cpp
vector<vector<int>> verticalOrder(TreeNode *root) {
  if (!root) return {};

  unordered_map<int, vector<int>> ret;

  int left = 0;
  int right = 0;

  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  while (!q.empty()) {
    pair<TreeNode *, int> cur = q.front();
    q.pop();

    TreeNode *node = cur.first;
    int x = cur.second;
    left = min(x, left);
    right = max(x, right);

    ret[x].push_back(node->val);
    if (node->left) {
      q.push({node->left, x - 1});
    }
    if (node->right) {
      q.push({node->right, x + 1});
    }
  }

  vector<vector<int>> answer;
  for (int i = left; i <= right; i++) {
    answer.push_back(ret[i]);
  }

  return answer;
}
```

## 고생한 점
