# 1372. Longest ZigZag Path in a Binary Tree

[링크](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

DFS를 진행하며 다음 노드로 넘어갈 때 마다 현재 노드의 방향와 다음 노드의 방향에 따라 길이를 갱신하며 넘겨준다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS로 탐색 시에 재귀호출을 이용할 경우 call stack에 O(N)의 공간 복잡도가 필요하다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     158      |    O(N)     |    O(N)     |

DFS를 이용해 루트 노드에서부터 다음 노드로 넘어간다.

이 때 현재 노드로 넘어온 방향을 알 경우, 다음 노드로 넘어갈 때의 방향과 비교해 길이를 갱신한다.

이 때 시작(루트)노드는 아무 방향을 갖지 않음에 유의한다.

```cpp
int answer = 0;

// -1:left 0:none 1:right
void recursive(TreeNode *node, int dir, int count) {
  answer = max(answer, count);

  if (node->left) {
    if (dir == 1 || dir == 0) {
      recursive(node->left, -1, count + 1);
    } else {
      recursive(node->left, -1, 1);
    }
  }
  if (node->right) {
    if (dir == -1 || dir == 0) {
      recursive(node->right, 1, count + 1);
    } else {
      recursive(node->right, 1, 1);
    }
  }
}

int longestZigZag(TreeNode *root) {
  recursive(root, 0, 0);
  return answer;
}
```

## 고생한 점
