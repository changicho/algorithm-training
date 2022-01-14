# 987. Vertical Order Traversal of a Binary Tree

[링크](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자.

각 노드들을 모두 순회하며 row, col에 대해서 알 수 있다.

해당 값들을 이후에 모두 정렬할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이를 각 col에 대해 저장한 뒤 row와 값에 대해 정렬할 수 있다.

K를 트리의 너비라고 하자.

이 경우 정렬할 때 한 col에는 평균적으로 N / K 개의 원소가 들어간다.

해당 노드에대해 정렬을 수행할 경우 O((N / K) \* log_2(N / K))의 시간 복잡도가 소요되며,

이를 K번 (모든 col)에 대해 반복하므로 총 시간 복잡도는 O(N \* log_2(N / K))가 된다.

### 공간 복잡도

각 원소들을 저장할 공간에 O(N)의 공간 복잡도를 사용한다.

### DFS with sort

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      4       | O(N \* log_2(N / K)) |    O(N)     |

모든 노드를 우선 순회하며 col끼리 묶는다.

이후 각 노드들을 row에 따라서, row가 같은 경우는 값에 따라 정렬한다.

col에 대해 BST기반의 map을 이용해 key, value 쌍으로 묶을 경우 이후에 가장 낮은 col부터 순회하며 정답을 채울 수 있다.

이를 구현하면 다음과 같다.

```cpp
struct Data {
  int val, row, col;

  bool operator<(const Data &b) const {
    if (row != b.row) {
      return row < b.row;
    }
    return val < b.val;
  }
};

map<int, vector<Data>> lineByCol;

void recursive(TreeNode *node, int col, int row) {
  lineByCol[col].push_back({node->val, row, col});

  if (node->left) {
    recursive(node->left, col - 1, row + 1);
  }
  if (node->right) {
    recursive(node->right, col + 1, row + 1);
  }
}

vector<vector<int>> verticalTraversal(TreeNode *root) {
  if (root) recursive(root, 0, 0);

  vector<vector<int>> answer;
  for (auto &it : lineByCol) {
    vector<int> line;

    sort(it.second.begin(), it.second.end());
    for (Data &d : it.second) {
      line.push_back(d.val);
    }
    answer.push_back(line);
  }

  return answer;
}
```

## 고생한 점
