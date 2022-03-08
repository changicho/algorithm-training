# 124. Binary Tree Maximum Path Sum

[링크](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N, 높이를 H라 하자.

모든 노드를 순회하며 path를 계산해야 하므로 O(N)의 시간 복잡도를 사용한다.

이 때 DFS로 순회할 경우 현재 노드에서 자식 노드들에 대해 탐색한 값을 이용해 현재 최적의 값을 갱신할 수 있다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

DFS로 탐색을 진행할 때 call stack에 쌓이는 공간 복잡도는 O(H)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(H)     |

각 노드에 대해서 해당 노드가 포함된 path의 최대값은 다음 경우들 중 하나이다.

- 현재 노드만 포함
- 현재 노드와 왼쪽 자식노드 path를 포함
- 현재 노드와 오른쪽 자식노드 path를 포함
- 현재 노드가 LCA(최소공통조상)이며 왼쪽, 오른쪽 path 포함

따라서 재귀 호출의 반환값으로 해당 노드가 끝점인 path에 대한 최대값을 반환하도록 구성했을 때, 위 4가지 값을 계산할 수 있다.

여기서 LCA인 경우는 path에 대한 끝점이 아니므로 반환하지 않는다.

이 때 empty path는 정답에 포함할 수 없으므로 정답의 초기값은 INT_MIN 으로 설정한다. (최소값)

이를 구현하면 다음과 같다.

```cpp
int getMaxPathSum(TreeNode *node, int &answer) {
  if (!node) return 0;

  int leftMax = getMaxPathSum(node->left, answer);
  int rightMax = getMaxPathSum(node->right, answer);

  // pick leftPath, pick rightPath, not pick either path
  int cur = max({node->val, leftMax + node->val, rightMax + node->val});

  // update answer
  // also check current node is root of subTree case
  answer = max({answer, cur, leftMax + rightMax + node->val});

  return cur;
}

int maxPathSum(TreeNode *root) {
  int answer = INT_MIN;
  getMaxPathSum(root, answer);

  return answer;
}
```

## 고생한 점

현재 노드가 LCA인 경우는 반환하지 않아야함
