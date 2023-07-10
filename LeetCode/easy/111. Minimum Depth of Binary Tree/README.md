# 111. Minimum Depth of Binary Tree

[링크](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자. (N <= 10^5)

모든 노드를 탐색하며 깊이를 구할 수 있으므로 시간 복잡도는 O(N) 이다.

### 공간 복잡도

최악의 경우 DFS, BFS에 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     298      |    O(N)     |    O(N)     |

DFS로 탐색을 진행하며 루트 노드에서부터 깊이를 증가시키며 인자로 넣어준다.

만약 현재 노드가 리프노드인 경우 정답을 갱신한다.

이 때 루트가 없는 경우 0을 반환한다.

```cpp
int answer = INT_MAX;

void recursive(TreeNode *node, int d) {
  if (!node) return;

  if (!node->left && !node->right) {
    answer = min(answer, d);

    return;
  }

  if (node->left) recursive(node->left, d + 1);
  if (node->right) recursive(node->right, d + 1);
}

int minDepth(TreeNode *root) {
  recursive(root, 1);

  if (answer == INT_MAX) return 0;
  return answer;
}
```

## 고생한 점
