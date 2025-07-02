# 333. Largest BST Subtree

[링크](https://leetcode.com/problems/largest-bst-subtree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N이라 하자.

DFS를 이용해 각 노드를 루트로 하는 서브트리가 BST인지 확인하고 정답을 갱신한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS에 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

DFS를 이용해 각 노드를 루트로 하는 서브트리가 BST인지 확인한다.

이 때 자식 노드들을 재귀적으로 호출한 반환값은 다음과 같다.

- count: 서브트리의 노드의 수
- leftRange: 서브트리의 왼쪽 범위 (최소값)
- rightRange: 서브트리의 오른쪽 범위 (최대값)

이를 이용해 현재 노드값과 자식들의 범위가 유효한지 확인한다.

만약 현재 노드가 BST의 조건을 만족하지 않는다면, -1을 반환하며 자식 노드가 BST의 조건을 만족하지 않는 경우 현재 노드또한 -1을 반환한다.

```cpp
struct Status {
  int count, leftRange, rightRange;
};

int answer = 0;

// count, leftRange, rightRange
Status recursive(TreeNode *node) {
  Status ret = {1, node->val, node->val};
  bool isFine = true;

  if (node->left) {
    Status range = recursive(node->left);
    if (range.count == -1 || ret.leftRange <= range.rightRange) {
      isFine = false;
    }

    ret.leftRange = min(ret.leftRange, range.leftRange);
    ret.rightRange = max(ret.rightRange, range.rightRange);
    ret.count += range.count;
  }
  if (node->right) {
    Status range = recursive(node->right);
    if (range.count == -1 || range.leftRange <= ret.rightRange) {
      isFine = false;
    }

    ret.leftRange = min(ret.leftRange, range.leftRange);
    ret.rightRange = max(ret.rightRange, range.rightRange);
    ret.count += range.count;
  }

  if (!isFine) return {-1, -1, -1};
  answer = max(answer, ret.count);
  return ret;
}

int largestBSTSubtree(TreeNode *root) {
  if (root) recursive(root);

  return answer;
}
```

## 고생한 점
