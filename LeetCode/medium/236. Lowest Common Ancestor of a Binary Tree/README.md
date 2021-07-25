# 236. Lowest Common Ancestor of a Binary Tree

[링크](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 노드의 수를 N이라 하자.

우선 모든 노드를 방문하며 p, q를 찾아야한다.

이 방문에 시간복잡도 O(N)이 필요하다.

이후 내부적으로 path를 찾기 위해서 path를 만들어줘야한다.

이에 O(N)의 시간복잡도가 소요되며, 해당 path를 순차적으로 방문하며 LCA를 찾아야한다.

혹은 재귀호출로 방문과 동시에 LCA를 찾을 수도 있다.

결과적으로 두 방법 모두 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

모든 노드를 방문하는데 O(N)의 공간 복잡도가 필요하다.

### 경로 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      19      |    O(N)     |    O(N)     |

루트에서부터 p와 q까지의 경로를 찾은 뒤, 해당 경로들의 분기가 일어나기 직전의 노드를 LCA라고 할 수 있다.

따라서 path를 찾고 이를 비교한다.

path를 찾는 데 다음과 같은 구조의 hash map을 이용한다.

- key : child node
- value : parent node

해당 hash map을 모든 노드에 대해서 갱신한 이후 p와 q의 부모에 대해서 탐색하며 경로를 찾는다.

이 경로는 p, q에서 root까지의 경로이므로 이를 뒤집으면 root에서 p, q까지의 경로를 찾을 수 있다.

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  // step1. make hash map (key : child, value : parent)
  unordered_map<TreeNode*, TreeNode*> um;

  // step2. fill hashmap
  queue<TreeNode*> que;
  que.push(root);

  while (!que.empty()) {
    TreeNode* cur = que.front();
    que.pop();

    if (!cur->left && !cur->right) continue;

    if (cur->left) {
      um[cur->left] = cur;
      que.push(cur->left);
    }
    if (cur->right) {
      um[cur->right] = cur;
      que.push(cur->right);
    }
  }

  // step3. find path of p, q from root
  TreeNode *pParent = p, *qParent = q;
  vector<TreeNode*> pPath, qPath;
  while (pParent) {
    pPath.emplace_back(pParent);
    pParent = um[pParent];
  }
  while (qParent) {
    qPath.emplace_back(qParent);
    qParent = um[qParent];
  }
  reverse(pPath.begin(), pPath.end());
  reverse(qPath.begin(), qPath.end());

  // step4. find branch point from root in pPath, qPath
  int limit = min(pPath.size(), qPath.size());
  TreeNode* answer = root;

  for (int i = 0; i < limit; i++) {
    if (pPath[i]->val != qPath[i]->val) break;
    answer = pPath[i];
  }

  return answer;
}
```

### post order

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      29      |    O(N)     |    O(N)     |

다음과 같은 함수를 생성한다.

- 현재 노드가 p, q일 경우 해당 노드를 반환함
- p, q가 아닐 경우 null을 반환함
- p와 q의 LCA인 경우 현재 노드를 반환함

현재 노드에서 자식 노드에 대해서 재귀호출을 진행하며 반환값을 받아오고 두 값이 존재하는 경우 자기 자신이 LCA임을 알 수 있다.

이는 LCA의 자식노드에서 분기하기 때문이다.

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode *leftRet = NULL, *rightRet = NULL;

  if (root->val == p->val) return p;
  if (root->val == q->val) return q;

  if (root->left) leftRet = lowestCommonAncestor(root->left, p, q);

  if (root->right) rightRet = lowestCommonAncestor(root->right, p, q);

  if (leftRet && rightRet) return root;
  if (leftRet && !rightRet) return leftRet;
  if (!leftRet && rightRet) return rightRet;

  return NULL;
}
```

### 오일러 경로

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |    O(N)     |    O(N)     |

오일러 경로를 이용해 LCA를 구할 수 있다.

오일러 경로로 노드들을 방문한 path를 구한다.

이후 p부터 q까지의 range 내부에서 가장 level이 낮은 노드를 구하면 해당 노드가 LCA가 된다.

```cpp
vector<TreeNode*> eulerPaths;
vector<int> levels;
// key : node's value, value : index of path
unordered_map<int, int> lastIndex;

void eulerTour(TreeNode*& root, int level) {
  lastIndex[root->val] = eulerPaths.size();
  eulerPaths.emplace_back(root);
  levels.emplace_back(level);

  if (root->left) {
    eulerTour(root->left, level + 1);

    lastIndex[root->val] = eulerPaths.size();
    eulerPaths.emplace_back(root);
    levels.emplace_back(level);
  }
  if (root->right) {
    eulerTour(root->right, level + 1);

    lastIndex[root->val] = eulerPaths.size();
    eulerPaths.emplace_back(root);
    levels.emplace_back(level);
  }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  // step1. make euler path
  eulerTour(root, 0);

  // step2. set range
  int left = lastIndex[p->val];
  int right = lastIndex[q->val];
  if (left > right) swap(left, right);

  // step3. find LCA index
  int index = left;
  for (int i = left; i <= right; i++) {
    if (levels[i] < levels[index]) {
      index = i;
    }
  }

  TreeNode* node = eulerPaths[index];
  return node;
}
```

## 고생한 점
