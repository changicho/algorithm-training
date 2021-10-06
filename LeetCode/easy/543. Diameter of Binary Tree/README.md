# 543. Diameter of Binary Tree

[링크](https://leetcode.com/problems/diameter-of-binary-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 개수를 N이라 하자.

모든 노드를 한번 순회해야 하므로 시간 복잡도는 O(N)이 소요된다.

거리를 계산할 때 각 모든 노드에 대해 최대 거리를 계산하며 탐색하면 되므로 하나의 노드에서 다른 노드까지 모두 탐색하지 않아도 된다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

DFS로 모든 노드를 방문할 경우 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(N)     |

정답은 다음 경우로 판별할 수 있다.

- 루트 노드를 지나는 경우
- 루트 노드를 지나지 않는 경우

따라서 각 노드를 탐색할 때마다, 해당 노드의 left, right에서의 각각의 최대 길이를 알아야한다.

그리고 루트 노드를 지나는 경우, 지나지 않는 경우에 대한 정답을 갱신한다.

DFS로 탐색할 경우 다음과 같이 나타낼 수 있다.

```cpp
int diameter(TreeNode *root) {
  if (!root) return 0;

  // 왼쪽 탐색
  int left = diameter(root->left);
  // 오른쪽 탐색
  int right = diameter(root->right);

  // 루트를 지나지 않는 경우, 현재 노드를 root로 하는 subTree일 때의 최대값 갱신
  answer = max(answer, left + right);
  // 현재 노드에서 가능한 최대값에 현재 노드값을 더한다.
  return max(left, right) + 1;
}
```

이를 이용해 다음과 같이 구할 수 있다.

```cpp
int answer = INT_MIN;
int diameter(TreeNode *root) {
  if (!root) return 0;

  int left = diameter(root->left);
  int right = diameter(root->right);

  answer = max(answer, left + right);

  return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root) {
  if (!root) return 0;

  diameter(root);

  return answer;
}
```

## 고생한 점
