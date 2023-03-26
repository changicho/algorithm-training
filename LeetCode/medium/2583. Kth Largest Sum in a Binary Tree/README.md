# 2583. Kth Largest Sum in a Binary Tree

[링크](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자. (N <= 10^5)

각 노드를 높이별로 BFS 순회하며 각 높이별 노드의 합을 구할 수있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

이후 각 합들을 정렬해 K번째 값을 구한다.

정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS 탐색에 O(N)의 공간 복잡도를 사용한다.

### BFS & 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     203      | O(N \* log_2(N)) |    O(N)     |

루트에서부터 각 높이별로 BFS를 진행하며 각 높이별 노드의 합을 구한다.

이후 이를 정렬한다.

만약 합의 갯수가 K보다 작은 경우 -1을 반환한다.

```cpp
long long kthLargestLevelSum(TreeNode *root, int k) {
  vector<long long> sums;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    long long curSum = 0;

    int size = q.size();
    while (size--) {
      TreeNode *cur = q.front();
      q.pop();

      curSum += cur->val;

      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }
    sums.push_back(curSum);
  }

  sort(sums.begin(), sums.end(), greater<long long>());

  if (sums.size() < k) {
    return -1;
  }
  return sums[k - 1];
}
```

## 고생한 점
