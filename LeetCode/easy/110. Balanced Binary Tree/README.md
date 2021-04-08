# 110. Balanced Binary Tree

[링크](https://leetcode.com/problems/balanced-binary-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 개수는 최대 5,000 이다. 모든 노드를 탐색하며 subtree의 높이를 비교해야 하므로 시간 복잡도는 O(N) 이다.

### 공간 복잡도

재귀함수를 호출하며 각 subtree의 높이를 저장하므로 공간 복잡도는 O(2 \* N) 이다.

### DFS

현재 노드에서 왼쪽, 오른쪽 subtree의 높이를 재귀적으로 탐색한다.

이 때 노드의 차가 1을 넘는 경우가 한번이라도 발생하면 정답은 false이다.

```cpp
bool isBalanced(TreeNode *root) {
  bool answer = true;
  int height = getHeight(root, 0, answer);

  return answer;
}

int getHeight(TreeNode *cur, int height, bool &answer) {
  if (!cur) return height - 1;

  int left = getHeight(cur->left, height + 1, answer);
  int right = getHeight(cur->right, height + 1, answer);

  if (abs(left - right) > 1) answer = false;

  return max(left, right);
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
