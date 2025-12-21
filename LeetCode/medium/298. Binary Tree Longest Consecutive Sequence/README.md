# 298. Binary Tree Longest Consecutive Sequence

[링크](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N이라 하자.

루트부터 DFS를 순회하며 순차적으로 증가하며 방문하는지 확인한다.

이에 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

DFS에 O(N)의 공간 복잡도를 가진다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 노드를 DFS로 순회하며 현재 노드를 방문했을 때의 조건을 만족하는 연속된 수의 개수를 갱신한다.

만약 현재 노드의 자식의 값이 현재 노드보다 1 큰 경우 연속된 수의 개수를 1 증가시킨다.

그 외의 경우 1로 초기화한다.

```cpp
int answer = 0;

void recursive(TreeNode* node, int count) {
  answer = max(answer, count);

  if (node->right) {
    int nextCount = 1;
    if (node->val + 1 == node->right->val) {
      nextCount = count + 1;
    }
    recursive(node->right, nextCount);
  }
  if (node->left) {
    int nextCount = 1;
    if (node->val + 1 == node->left->val) {
      nextCount = count + 1;
    }
    recursive(node->left, nextCount);
  }
}

int longestConsecutive(TreeNode* root) {
  if (root) recursive(root, 1);
  return answer;
}
```

## 고생한 점
