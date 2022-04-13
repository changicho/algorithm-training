# 2236. Root Equals Sum of Children

[링크](https://leetcode.com/problems/root-equals-sum-of-children/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

루트와 두 자식의 값을 비교하면 된다.

O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 추가 공간이 필요하지 않다.

### 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(1)     |    O(1)     |

트리의 노드의 모양과 갯수는 동일함이 보장된다. (3개)

따라서 직접 접근해 풀이한다.

```cpp
bool checkTree(TreeNode *root) {
  return root->val == root->left->val + root->right->val;
}
```

## 고생한 점
