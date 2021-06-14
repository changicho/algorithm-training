# 103. Binary Tree Zigzag Level Order Traversal

[링크](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 모든 노드의 개수를 N이라 하자.

우선 한번 모든 노드를 순회해야 하므로 outer 시간 복잡도는 O(N)이다.

내부적으로 트리의 노드들을 지그재그로 순회해야 한다. 이 때 방문 순서를 뒤집는 연산을 수행하는 데 걸리는 시간 복잡도는 상수이다. O(1)

따라서 모든 트리노드를 지그재그로 순회하는데 들어가는 시간 복잡도는 O(N)이다.

### 공간 복잡도

정답에 노드의 방문 순서를 저장해야 하며 이는 최종적으로 O(N)이다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

BFS를 이용해 계층별로 트리를 순회한다.

그리고 각 층의 방문 순서대로 배열에 담은 뒤 정답에 추가한다.

이 때 짝수번째 층을 방문한 경우 순서를 뒤집고 정답에 추가한다.

각 계층별 순회를 끝낸 후 뒤집는 연산을 수행하는 이유는,

만약 매번 방문 순서를 계층마다 뒤집을 (left, right가 아닌 right, left)경우

현재 노드의 자식 노드들의 순서는 변경할 수 있지만 형제 노드들의 자식 노드의 순서는 기존에 방문한 형제 노드끼리 방문 순서를 그대로 유지하기 때문이다.

```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  vector<vector<int>> answer;

  queue<TreeNode *> q;
  if (root) q.push(root);
  bool convert = false;

  while (!q.empty()) {
    vector<int> line;
    for (int i = 0, size = q.size(); i < size; i++) {
      TreeNode *cur = q.front();
      q.pop();

      line.push_back(cur->val);

      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }

    if (convert) reverse(line.begin(), line.end());
    convert = !convert;

    answer.push_back(line);
  }

  return answer;
}
```

## 고생한 점
