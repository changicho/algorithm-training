# 1973. Count Nodes Equal to Sum of Descendants

[링크](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

재귀 호출을 이용해 각 노드마다 자식노드들의 값들의 합을 구하고 이를 비교해야 한다.

이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

재귀 호출 call stack에 O(N)의 공간 복잡도를 사용한다.

합의 범위가 int형을 벗어날 수 있음에 유의한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     232      |    O(N)     |    O(N)     |

재귀호출을 이용해 현재 노드를 루트로 하는 서브트리의 노드의 값들의 합을 구하는 함수를 생성한다.

이 과정에서 자식노드들의 합을 구하고 이를 이용해 현재 노드의 값을 비교한다.

이를 루트 노드에서 부터 반복한다.

```cpp
int answer = 0;

long long recursive(TreeNode *node) {
  long long childrenSum = 0;
  if (node->left) childrenSum += recursive(node->left);
  if (node->right) childrenSum += recursive(node->right);

  if (node->val == childrenSum) answer++;

  return childrenSum + node->val;
}

int equalToDescendants(TreeNode *root) {
  if (root) recursive(root);

  return answer;
}
```

## 고생한 점
