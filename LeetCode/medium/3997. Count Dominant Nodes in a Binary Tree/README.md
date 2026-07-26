# 3997. Count Dominant Nodes in a Binary Tree

[링크](https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N, 깊이를 H라 하자.

각 노드별로 재귀호출로 순회하며 정답을 갱신할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS에 O(H)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      33      |    O(N)     |    O(H)     |

각 노드를 순회하며 재귀함수의 반환값으로 현재 노드를 루트로 하는 subTree의 가장 큰 값을 반환한다.

이중 자식들의 최대값과 현재값을 포함해 현재값이 최대값인 경우 정답을 증가시킨다.

이를 반복한다.

```cpp
int answer = 0;

int dfs(TreeNode* node) {
  if (!node) return -1;
  int ret = node->val;

  int left = dfs(node->left);
  int right = dfs(node->right);

  ret = max({ret, left, right});
  if (ret == node->val) answer++;
  return ret;
}

int countDominantNodes(TreeNode* root) {
  if (root) dfs(root);

  return answer;
}
```

## 고생한 점
