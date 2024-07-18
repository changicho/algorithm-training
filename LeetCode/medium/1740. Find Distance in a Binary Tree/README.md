# 1740. Find Distance in a Binary Tree

[링크](https://leetcode.com/problems/find-distance-in-a-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

LCA를 사용할 경우 O(N)의 시간 복잡도가 소요된다.

DFS를 이용할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

DFS를 이용할 경우 재귀 호출로 인해 call stack에 최대 O(N)의 공간 복잡도가 필요하다.

### LCA

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      41      |    O(N)     |    O(N)     |

각 노드마다 루트에서부터 깊이를 저장하고, 부모 노드를 저장한다.

이후 p, q 노드의 깊이를 비교해 같은 깊이로 만든 뒤 한칸씩 위로 이동한다.

이를 두 노드가 만날 때 까지 반복한다.

```cpp
unordered_map<int, int> parents;
unordered_map<int, int> depths;

void preprocess(TreeNode *node, int depth) {
  depths[node->val] = depth;

  if (node->left) {
    parents[node->left->val] = node->val;
    preprocess(node->left, depth + 1);
  }
  if (node->right) {
    parents[node->right->val] = node->val;
    preprocess(node->right, depth + 1);
  }
}

int findDistance(TreeNode *root, int p, int q) {
  preprocess(root, 0);

  int pDepth = depths[p], qDepth = depths[q];

  if (pDepth < qDepth) {
    swap(p, q);
    swap(pDepth, qDepth);
  }

  int answer = 0;
  while (pDepth > qDepth) {
    answer++;
    p = parents[p];
    pDepth--;
  }

  while (p != q) {
    answer += 2;
    p = parents[p];
    q = parents[q];
  }
  return answer;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      27      |    O(N)     |    O(N)     |

재귀호출의 반환값으로 p, q 노드까지의 거리를 반환한다.

이 경우 두 노드의 LCA를 방문했을 때 두 노드의 거리를 계산할 수 있다.

```cpp
int answer = INT_MAX;
// pDist, qDist
pair<int, int> recursive(TreeNode *node, int p, int q) {
  int pDist = node->val == p ? 0 : -1;
  int qDist = node->val == q ? 0 : -1;

  if (node->left) {
    pair<int, int> ret = recursive(node->left, p, q);

    if (ret.first != -1) pDist = ret.first;
    if (ret.second != -1) qDist = ret.second;
  }

  if (node->right) {
    pair<int, int> ret = recursive(node->right, p, q);

    if (ret.first != -1) pDist = ret.first;
    if (ret.second != -1) qDist = ret.second;
  }

  if (pDist != -1 && qDist != -1) {
    answer = min(answer, pDist + qDist);
  }

  if (pDist != -1) pDist++;
  if (qDist != -1) qDist++;

  return {pDist, qDist};
}

int findDistance(TreeNode *root, int p, int q) {
  recursive(root, p, q);

  return answer;
}
```

## 고생한 점
