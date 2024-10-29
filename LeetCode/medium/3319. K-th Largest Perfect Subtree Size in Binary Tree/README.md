# 3319. K-th Largest Perfect Subtree Size in Binary Tree

[링크](https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N, 입력받은 수를 K라 하자.

DFS로 트리를 순회하며 각 노드를 루트로 하는 subTree가 perfect인지 판별하는데 O(N)의 시간 복잡도가 필요하다.

각 과정마다 K번째 perfect subTree의 크기를 구하는데 힙을 사용할 수 있다. 

이 경우 총 시간 복잡도는 O(N \* log_2(K))이다.

### 공간 복잡도

DFS에 O(N)의 공간 복잡도가 필요하다. heap에 O(K)의 공간 복잡도가 필요하다.

### DFS & heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      53      | O(N \* log_2(K)) |  O(N + K)   |

DFS를 수행하며 각 과정마다 현재 노드가 루트인 서브 트리가 perfect인지를 판별한다.

이 때 현재 노드의 두 자식 left, right의 서브트리의 크기가 같은지, 둘다 perfect인지를 판별한다.

리프 노드는 perfect함에 유의한다.

이후 현재 노드의 서브트리의 크기를 구하고, 이 값이 perfect한 경우 min heap에 삽입한다.

min heap의 크기가 K를 넘는 경우 가장 작은 값을 pop한다.

이후 min heap의 top에는 K번째로 큰 perfect 서브트리의 크기가 존재한다.

만약 min heap의 크기가 K보다 작은 경우 -1을 반환한다.

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

// {isPerfect, count}
pair<bool, int> recursive(TreeNode *node, int k) {
  int count = 1;

  bool isPerfect = true;
  int leftCount = 0, rightCount = 0;
  if (node->left) {
    auto ret = recursive(node->left, k);

    if (!ret.first) isPerfect = false;
    leftCount = ret.second;
  }
  if (node->right) {
    auto ret = recursive(node->right, k);

    if (!ret.first) isPerfect = false;
    rightCount = ret.second;
  }

  if (leftCount != rightCount) {
    isPerfect = false;
  }
  count += leftCount + rightCount;

  if (isPerfect) {
    pq.push(count);
    if (pq.size() > k) pq.pop();
  }

  return {isPerfect, count};
}

int kthLargestPerfectSubtree(TreeNode *root, int k) {
  if (root) recursive(root, k);

  if (pq.size() < k) return -1;

  return pq.top();
}
```

## 고생한 점
