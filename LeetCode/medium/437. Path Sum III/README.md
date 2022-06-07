# 437. Path Sum III

[링크](https://leetcode.com/problems/path-sum-iii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 개수를 N이라 하자.

한 노드에서 모든 자식 노드를 탐색하는 데 O(N)의 시간 복잡도가 소요된다.

각 노드들마다 모두 자식 노드들에 대해서 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

루트 노드에서부터 재귀호출을 통해서 자식 노드들을 탐색하고 그때마다의 부분합을 이용해 구할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

재귀 호출을 사용할 경우 호출 스택에 최대 O(N)의 공간 복잡도를 사용한다.

부분합을 이용할 경우 O(N)의 추가 공간이 필요하다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |   O(N^2)    |    O(N)     |

루트에서부터 각 노드들을 탐색한다.

이후 각 노드를 root로 하는 서브트리를 탐색하며 부분합이 target이 되는 경우 더한다.

이 때 현재 부분합이 target값과 동일하더라도 이후 탐색하며 또 target과 같은 값이 나올 수 있으므로 모두 탐색함에 유의한다.

```cpp
int answer = 0;

void recursive(TreeNode *node, int target, long long sum) {
  if (!node) return;

  sum += node->val;
  if (sum == target) {
    answer += 1;
  }

  recursive(node->left, target, sum);
  recursive(node->right, target, sum);
}

int pathSum(TreeNode *root, int targetSum) {
  queue<TreeNode *> q;
  if (root) q.push(root);

  while (!q.empty()) {
    TreeNode *cur = q.front();
    q.pop();

    recursive(cur, targetSum, 0);

    if (cur->left) q.push(cur->left);
    if (cur->right) q.push(cur->right);
  }
  return answer;
}
```

DFS로 각 노드를 시작점으로 탐색하는 경우 다음과 같다.

```cpp
int countSame = 0;

void recursive(TreeNode *node, long long curSum, long long target) {
  if (!node) return;

  curSum += node->val;
  if (curSum == target) countSame++;

  if (node->left) recursive(node->left, curSum, target);
  if (node->right) recursive(node->right, curSum, target);
}

void startNode(TreeNode *node, int target) {
  if (!node) return;

  recursive(node, 0, target);

  if (node->left) startNode(node->left, target);
  if (node->right) startNode(node->right, target);
}

int pathSum(TreeNode *root, int targetSum) {
  startNode(root, targetSum);

  return countSame;
}
```

### 부분합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(N)     |

루트 노드에서부터 탐색을 진행한다.

이 때 현재까지의 합을 저장해 이후 자식 노드들을 탐색할 때 이용하며, 탐색이 끝난 경우 현재까지의 합을 제거한다.

이는 겹치지 않는 다른 subTree를 탐색했을 때의 합이 서로 영향받지 않게하기 위함이다.

따라서 현재 상황에서 현재까지의 합 - target값이 이전에 나온 경우 해당 subTree의 부분을 뺄 경우 target을 만들 수 있음이 보장된다.

이를 이용해 루트 노드에서부터 모든 경우의 수를 탐색한다.

부분합들을 저장하기 위해 hash map을 사용한다.

```cpp
int countSame = 0;

unordered_map<long long, int> sums;

void recursive(TreeNode *node, long long curSum, int target) {
  curSum += node->val;

  if (curSum == target) countSame++;
  countSame += sums[curSum - target];
  sums[curSum] += 1;

  if (node->left) recursive(node->left, curSum, target);
  if (node->right) recursive(node->right, curSum, target);

  sums[curSum] -= 1;
}

int pathSum(TreeNode *root, int targetSum) {
  if (root) recursive(root, 0, targetSum);

  return countSame;
}
```

## 고생한 점
