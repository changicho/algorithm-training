# 776. Split BST

[링크](https://leetcode.com/problems/split-bst/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N이라 하자.

재귀 호출을 이용해 트리를 탐색하며, 주어진 값에 따라 노드를 분리해야 한다.

이에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

재귀 호출을 이용해 탐색할 경우 O(N)의 공간 복잡도를 사용한다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 단계마다 target 노드에 붙일 값과 붙이지 않을 값으로 나눈다.

함수의 반환값이 다음과 같다고 하자.

- {left, right} : left는 target보다 작은 값들로 이루어진 트리, right는 target보다 큰 값들로 이루어진 트리

이 경우 현재 노드의 값이 target보다 큰 경우와 이하인 경우에 따라 나눌 수 있다.

- target 초과 : 현재 노드의 left에 대해서 재귀 호출을 수행하고, left를 갱신한다.
- target 이하 : 현재 노드의 right에 대해서 재귀 호출을 수행하고, right를 갱신한다.

```cpp
vector<TreeNode *> splitBST(TreeNode *root, int target) {
  if (!root) {
    return {NULL, NULL};
  }

  if (root->val > target) {
    vector<TreeNode *> left = splitBST(root->left, target);

    root->left = left[1];
    return {left[0], root};
  } else {
    vector<TreeNode *> right = splitBST(root->right, target);

    root->right = right[0];
    return {root, right[1]};
  }
}
```

## 고생한 점
