# 2458. Height of Binary Tree After Subtree Removal Queries

[링크](https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

모든 경우를 직접 계산할 경우 O(Q \* N)의 시간 복잡도가 필요하다. 이는 제한시간 내에 불가능하다.

트리를 두번 순회하며 각각 순회하는 순서를 변경해 순회할 수 있다.

각 과정에서 지금까지 도달한 최대 높이를 저장하며, 이를 이용해 현재 노드를 제거했을 때의 높이를 갱신할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

이후 각 쿼리를 수행하는 데 O(Q)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 노드마다 높이를 저장하는데 O(N)의 공간 복잡도가 필요하다.

정답에 O(Q)의 공간 복잡도가 필요하다.

### left and right traversal

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |  O(N + Q)   |  O(N + Q)   |

각 노드를 순회할 때 L->R, R->L 순서로 순회하며 현재 노드까지 순회하며 도달한 최대 높이를 저장한다.

이 때 해당 값이 현재 노드를 삭제했을 때 트리의 최대 높이가 된다.

```cpp
int heights[100001];
int maximum = 0;

void leftToRight(TreeNode* node, int height) {
  if (!node) return;

  heights[node->val] = maximum;

  maximum = max(maximum, height);

  leftToRight(node->left, height + 1);
  leftToRight(node->right, height + 1);
}

void rightToLeft(TreeNode* node, int height) {
  if (!node) return;

  heights[node->val] = max(heights[node->val], maximum);

  maximum = max(height, maximum);

  rightToLeft(node->right, height + 1);
  rightToLeft(node->left, height + 1);
}

vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
  maximum = 0;
  leftToRight(root, 0);
  maximum = 0;
  rightToLeft(root, 0);

  vector<int> answer;
  for (int& query : queries) {
    answer.emplace_back(heights[query]);
  }

  return answer;
}
```

## 고생한 점
