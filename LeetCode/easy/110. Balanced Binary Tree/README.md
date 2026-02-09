# 110. Balanced Binary Tree

[링크](https://leetcode.com/problems/balanced-binary-tree/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

재귀 호출을 이용하며 자식 노드의 높이를 비교할 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

재귀 호출에 O(N)의 공간 복잡도를 가진다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

Balanced Binary Tree는 각 노드에 대해서 왼쪽 subtree와 오른쪽 subtree의 높이 차이가 1 이하인 트리를 의미한다.

현재 노드에서 왼쪽, 오른쪽 subtree의 높이를 재귀적으로 탐색한다.

이 때 노드의 차가 1을 넘는 경우가 한번이라도 발생하면 정답은 false이다.

```cpp
bool answer = true;

int recursive(TreeNode* node) {
  if (!node) {
    return 0;
  }

  int left = recursive(node->left);
  int right = recursive(node->right);

  if (abs(left - right) > 1) {
    answer = false;
  }

  return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
  recursive(root);
  return answer;
}
```

## 고생한 점
