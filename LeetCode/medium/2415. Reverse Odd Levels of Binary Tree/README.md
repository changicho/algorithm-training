# 2415. Reverse Odd Levels of Binary Tree

[링크](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

BFS를 이용할 경우 O(N)의 시간 복잡도가 필요하다.

DFS를 이용할 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

BFS에 O(N)의 공간 복잡도가 필요하다.

DFS에 O(log_2(N))의 공간 복잡도가 필요하다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     | O(log_2(N)) |

트리는 완전 이진 트리이다.

트리의 depth가 홀수인 경우 해당 depth의 노드들의 값의 순서를 뒤집어야한다.

DFS를 수행하며 중앙을 기준으로 왼쪽과 오른쪽을 서로 바꾸는 방법을 이용한다.

따라서 각 단계별로 바뀌야 하는 자식들을 교차해 넘겨준다.

```cpp
   0
 1   2
3 4 5 6
```

트리의 상태가 위와 같은 경우 3,6과 4,5가 세트가 되며 이 값들을 서로 바꿔준다.

```cpp
void recursive(TreeNode* left, TreeNode* right, int depth) {
  if (!left || !right) return;

  if (depth % 2 == 0) {
    swap(left->val, right->val);
  }

  recursive(left->left, right->right, depth + 1);
  recursive(left->right, right->left, depth + 1);
}

TreeNode* reverseOddLevels(TreeNode* root) {
  recursive(root->left, root->right, 0);

  return root;
}
```

## 고생한 점
