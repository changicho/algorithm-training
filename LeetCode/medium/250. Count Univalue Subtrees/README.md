# 250. Count Univalue Subtrees

[링크](https://leetcode.com/problems/count-univalue-subtrees/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 모든 노드의 개수를 N이라 하자.

각 노드별로 자식들이 현재 노드와 같은 value를 가지는지 판단해야 한다.

재귀적으로 자식 노드들의 값이 같은지 여부를 받아 count를 수행할 경우 한번의 순회로 해결이 가능하다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

재귀호출을 이용할 경우 call stack에 최악의 경우 O(N)의 공간 복잡도가 필요하다.

이는 트리가 한쪽으로 치우친 경우이다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

count를 할 수 있는 경우는 다음과 같다.

- 현재 노드가 리프 노드
- 현재 노드의 왼쪽, 오른쪽 자식들이 모두 자신과 같은 값인경우

따라서 재귀호출을 이용하며, 반환 값으로 subTree의 값이 자기 자신과 값이 모두 같은지 판별한다.

비교는 다음 2가지 방법으로 가능하다

- 부모와 자신의 값을 비교
- 자신과 자식의 값을 비교

```cpp
// 자식과 부모를 비교
int answer = 0;

bool recursive(TreeNode *node, int parent) {
  if (!node->left && !node->right) {
    answer += 1;
    return true;
  }

  bool isLeftValid = true, isRightValid = true;
  if (node->left) {
    isLeftValid = recursive(node->left, node->val);
    isLeftValid = isLeftValid && node->val == node->left->val;
  }
  if (node->right) {
    isRightValid = recursive(node->right, node->val);
    isRightValid = isRightValid && node->val == node->right->val;
  }

  if (isLeftValid && isRightValid) {
    answer += 1;
    return true;
  }
  return false;
}

int countUnivalSubtrees(TreeNode *root) {
  if (root) recursive(root, root->val);

  return answer;
}
```

```cpp
// 자신과 자식을 비교
int answer = 0;

bool recursive(TreeNode *node, int val) {
  if (!node) return true;

  bool isLeftValid = recursive(node->left, node->val);
  bool isRightValid = recursive(node->right, node->val);

  if (!isLeftValid || !isRightValid) return false;

  answer++;
  return node->val == val;
}

int countUnivalSubtrees(TreeNode *root) {
  recursive(root, 0);
  return answer;
}
```

## 고생한 점
