# 951. Flip Equivalent Binary Trees

[링크](https://leetcode.com/problems/flip-equivalent-binary-trees/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

각 두 노드에서 자식들을 비교할 때 swap한 경우와 그렇지 않은 경우를 비교해야 한다.

재귀호출로 구현한 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀호출에 O(N)의 공간 복잡도가 필요하다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

현재 root1, root2가 같은지 비교하고 다르다면 false를 반환한다.

이 때 자식에 대해서 순회할 때 다음과 같은 경우를 비교한다.

- 두 root의 left, right끼리 비교하는 경우
- 자식을 교차해서 비교하는 경우

두 경우 중 하나라도 true인 경우 true를 반환한다.

```cpp
bool flipEquiv(TreeNode *root1, TreeNode *root2) {
  if (!root1 && !root2) return true;
  if (!root1 || !root2) return false;
  if (root1->val != root2->val) return false;

  bool noSwap = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);

  bool swap = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

  return swap || noSwap;
}
```

## 고생한 점
