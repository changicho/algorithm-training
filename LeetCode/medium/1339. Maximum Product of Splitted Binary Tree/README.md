# 1339. Maximum Product of Splitted Binary Tree

[링크](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

각 노드를 순회하며 자식 노드들 중 한쪽을 제외하고 탐색을 진행할 수 있다.

이 경우 시작 노드를 정하는 데 O(N)의 시간 복잡도를, 이후 모든 노드를 탐색하는 데 O(N^2)의 시간 복잡도를 사용한다.

기존에 모든 노드의 합을 구하고 재귀 호출 과정에서 현재 노드를 서브트리의 루트로 했을 때의 값을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀 호출에 트리의 높이만큼의 공간 복잡도를 사용한다. 이에 O(H)의 공간 복잡도를 사용한다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     308      |    O(N)     |    O(H)     |

각 노드들을 순회하며, 현재 노드를 루트로 하는 서브트리의 합을 반환하도록 구성한다.

이 경우 호출 과정에서 현재 노드의 값과 자식 노드들의 합을 할 수 있다.

이를 이용해 현재 노드를 루트 노드로 하는 서브트리의 합을 바로 알 수 있으므로 이 값과 기존에 미리 구한 모든 노드의 합을 이용해 정답을 갱신할 수 있다.

```cpp
long long MOD = 1e9 + 7;
long long sum = 0;
long long answer = 0;

void makeSum(TreeNode *node) {
  if (!node) return;
  sum += node->val;

  if (node->left) makeSum(node->left);
  if (node->right) makeSum(node->right);
}

int recursive(TreeNode *node) {
  if (!node) return 0;
  long long ret = node->val;

  if (node->left) {
    ret += recursive(node->left);
  }
  if (node->right) {
    ret += recursive(node->right);
  }

  long long cur = (ret * (sum - ret));

  answer = max(answer, cur);
  return ret;
}

int maxProduct(TreeNode *root) {
  makeSum(root);

  recursive(root);

  return answer % MOD;
}
```

## 고생한 점
