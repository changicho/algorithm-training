# 2385. Amount of Time for Binary Tree to Be Infected

[링크](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

모든 노드를 순회하며 연결관계를 생성하고, 이후 감염된 노드부터 BFS를 이용해 모든 노드까지 감염되는 시간을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 노드를 다시 순회하며 연결 관계를 생성할 경우 O(N)의 공간 복잡도를 사용한다.

BFS에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1174     |    O(N)     |    O(N)     |

트리의 루트부터 BFS를 수행하며 노드의 연결관계를 그래프로 변경한다.

이후 감염된 노드부터 BFS로 다른 노드들을 탐색한다.

이 때 제일 멀리 있는 노드까지의 거리가 정답이 되므로, 최장거리를 탐색한다.

```cpp
int amountOfTime(TreeNode *root, int start) {
  unordered_map<int, vector<int>> graph;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *cur = q.front();
    q.pop();

    if (cur->left) {
      graph[cur->val].push_back(cur->left->val);
      graph[cur->left->val].push_back(cur->val);

      q.push(cur->left);
    }
    if (cur->right) {
      graph[cur->val].push_back(cur->right->val);
      graph[cur->right->val].push_back(cur->val);

      q.push(cur->right);
    }
  }

  queue<int> qVal;
  qVal.push(start);
  unordered_set<int> visited;
  visited.insert(start);

  int time = 0;
  while (!qVal.empty()) {
    int size = qVal.size();
    while (size--) {
      int cur = qVal.front();
      qVal.pop();

      for (int &next : graph[cur]) {
        if (visited.count(next)) continue;
        visited.insert(next);

        qVal.push(next);
      }
    }
    time++;
  }
  return time - 1;
}
```

## 고생한 점
