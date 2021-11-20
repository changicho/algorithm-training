# 366. Find Leaves of Binary Tree

[링크](https://leetcode.com/problems/find-leaves-of-binary-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 개수를 N이라 하자.

매번 트리의 리프 노드들을 탐색하며, 이 노드들을 삭제하며 루트 노드가 삭제 될 때까지 반복해 풀이할 수 있다.

이 경우 한번 리프 노드를 순회하는데 O(N)의 시간 복잡도가 소요되며, 최악의 경우 이를 N번 반복하게 되므로 시간 복잡도는 O(N^2)가 된다.

각 노드들이 가지고 있는 최대 자식의 높이값으로 정렬하고 이를 높이값마다 방문해 풀이할 수 있다. 이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

혹은 매번 탐색할 때마다 높이값에 해당하는 정답 배열에 삽입할 수 있다. 이 경우 시간 복잡도는 O(N)이 된다.

### 공간 복잡도

DFS로 트리의 모든 노드를 탐색할 때 call stack에 최대 N개까지 쌓일 수 있으므로 공간 복잡도는 O(N)이다.

정답 배열에 사용하는 공간 복잡도 또한 O(N)을 차지한다.

### leaf노드 삭제

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(N^2)    |    O(N)     |

DFS로 루트에서부터 노드를 탐색한다. 동시에 인자로 받은 노드가 리프 노드인지 여부를 반환한다.

이 때 현재 노드가 leaf 노드인 경우 현재 노드를 큐에 삽입하고 리프노드임을 반환한다.

만약 현재 노드의 자식 노드가 리프 노드인 경우 이를 삭제한다.

이후 큐에 담긴 노드들의 값들을 정답으로 포함하고, 큐를 비운다.

이를 루트 노드가 삭제될 때 까지 반복한다.

```cpp
queue<TreeNode *> q;

bool isLeaf(TreeNode *node) {
  if (!node->left && !node->right) {
    q.push(node);
    return true;
  }

  bool isLeftLeaf = node->left && isLeaf(node->left);
  bool isRightLeaf = node->right && isLeaf(node->right);

  if (isLeftLeaf) node->left = NULL;
  if (isRightLeaf) node->right = NULL;

  return false;
}

vector<vector<int>> findLeaves(TreeNode *root) {
  vector<vector<int>> answer;
  if (!root) return answer;

  bool isRootLeaf = false;

  while (!isRootLeaf) {
    vector<int> line;
    isRootLeaf = isLeaf(root);

    while (!q.empty()) {
      TreeNode *cur = q.front();
      q.pop();
      line.push_back(cur->val);
    }

    answer.push_back(line);
  }

  return answer;
}
```

### 정렬 by depth

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(N \* log_2(N)) |    O(N)     |

각 노드들을 탐색하며 노드의 자식으로 탐색했을 때 가장 depth가 긴 값과, value를 같이 저장한다.

이를 depth 순으로 정렬한다.

이후 정답에 해당 depth 순으로 삽입한다.

```cpp
struct Data {
  int depth;
  int val;

  bool operator<(const Data &b) const { return depth < b.depth; };
};
vector<Data> datum;

int recursive(TreeNode *root) {
  // leaf node case
  if (!root->left && !root->right) {
    datum.push_back({0, root->val});
    return 0;
  }

  int leftDepth = 0, rightDepth = 0;

  if (root->left) leftDepth = recursive(root->left) + 1;
  if (root->right) rightDepth = recursive(root->right) + 1;

  int depth = max(leftDepth, rightDepth);
  datum.push_back({depth, root->val});
  return depth;
}

vector<vector<int>> findLeaves(TreeNode *root) {
  vector<vector<int>> answer;
  if (root) recursive(root);

  sort(datum.begin(), datum.end());

  int size = datum.back().depth;
  answer.resize(size + 1);

  for (Data &data : datum) {
    answer[data.depth].push_back(data.val);
  }

  return answer;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

DFS로 순회함과 동시에 정답 배열에 depth에 해당하는 index에 노드의 값을 삽입한다.

이 때 정답 배열의 크기가 현재 depth를 index로 잡을 수 없는 경우 빈 배열을 정답 배열에 삽입해 크기를 맞춰준다.

```cpp
vector<vector<int>> answer;

int recursive(TreeNode *root) {
  // leaf node case
  if (!root->left && !root->right) {
    if (answer.size() < 1) {
      answer.push_back({});
    }
    answer[0].push_back(root->val);
    return 0;
  }

  int leftDepth = 0, rightDepth = 0;

  if (root->left) leftDepth = recursive(root->left) + 1;
  if (root->right) rightDepth = recursive(root->right) + 1;

  int depth = max(leftDepth, rightDepth);
  if (answer.size() < depth + 1) {
    answer.push_back({});
  }
  answer[depth].push_back(root->val);
  return depth;
}

vector<vector<int>> findLeaves(TreeNode *root) {
  if (root) recursive(root);

  return answer;
}
```

## 고생한 점

visited 배열을 이용한 경우 삭제된 리프노드들에 대한 처리를 NULL인 경우 외에도 visited또한 체크해야 하는 것을 잊었었다.

depth를 계산할 때 현재 노드가 포함되므로 +1을 해줘야 한다.
