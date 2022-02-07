# 2096. Step-By-Step Directions From a Binary Tree Node to Another

[링크](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N, 높이를 H라 하자.

두 노드간의 최단 이동경로를 구하기 위해 LCA (최소 공통 조상)을 사용한다.

각 노드들을 탐색하며 value로 접근 가능하도록 구성한다.

이후 LCA를 구한 뒤 다음 두 경로를 구한다.

- start->LCA
- LCA->dest

두 노드의 위치를 탐색하는 데 O(N)의 시간 복잡도를 사용하며, LCA를 구하고 경로를 찾는데 O(H)의 시간 복잡도를 사용한다.

혹은 루트 노드에서부터 start, dest노드까지 path를 탐색한 뒤 공통부분 (LCA 이후의 경로)를 삭제하고 문제를 풀이할 수 있다.

이 경우 각 두 노드까지 탐색하는데 O(N)의 시간복잡도로 풀이가 가능하다.

### 공간 복잡도

시작 노드에서부터 LCA까지의 경로에 최대 O(L)의 공간 복잡도를 사용한다.

각 value마다 특정 노드에 바로 접근 가능하기 위해 hash map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### LCA (path)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     172      |    O(N)     |    O(L)     |

루트 노드에서부터 각 노드까지의 path를 DFS를 이용해 찾는다.

이후 두 path에서 공통된 prefix가 끝나는 지점이 LCA이다. (두 노드를 찾기위해 탐색에 분기하는 시점)

이를 이용해 path를 구한 뒤 prefix를 제거하고 정답을 구할 수 있다.

```cpp
bool find(TreeNode* node, int val, string& path) {
  if (node->val == val) return true;

  if (node->left && find(node->left, val, path)) {
    path.push_back('L');
  } else if (node->right && find(node->right, val, path)) {
    path.push_back('R');
  }

  return !path.empty();
}

string getDirections(TreeNode* root, int startValue, int destValue) {
  string startPath, destPath;

  // fill start, dest path
  find(root, startValue, startPath);
  find(root, destValue, destPath);

  while (!startPath.empty() && !destPath.empty() &&
          startPath.back() == destPath.back()) {
    startPath.pop_back();
    destPath.pop_back();
  }

  reverse(destPath.begin(), destPath.end());
  return string(startPath.length(), 'U') + destPath;
}
```

### LCA (node)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     700      |    O(N)     |    O(N)     |

두 노드의 LCA를 찾은 뒤에 경로를 생성하는 방법을 사용할 수 도 있다.

노드를 찾은뒤 path를 만드는 방법을 이용할 경우 각 노드에 빠르게 접근하기 위해 hash map을 이용한다.

이를 이용해 path를 재구성할 경우 느리다.

```cpp
// data structure
unordered_map<int, TreeNode*> table;
unordered_map<int, TreeNode*> parents;
unordered_map<int, int> depths;
```

```cpp
// initialize
void recursive(TreeNode* node, int depth) {
  if (!node) return;

  depths[node->val] = depth;
  table[node->val] = node;

  if (node->left) {
    parents[node->left->val] = node;
    recursive(node->left, depth + 1);
  }
  if (node->right) {
    parents[node->right->val] = node;
    recursive(node->right, depth + 1);
  }
}
```

```cpp
string getDirections(TreeNode* root, int startValue, int destValue) {
  // search LCA
  // find LCA -> startVal, reverse it path
  // find LCA -> destVal, reverse it path

  recursive(root, 0);

  TreeNode *start = table[startValue], *dest = table[destValue];

  string startToLCA = "", destToLCA = "";

  // trim depth of start
  while (depths[start->val] > depths[dest->val]) {
    startToLCA += "U";
    start = parents[start->val];
  }
  // trim depth of dest
  while (depths[dest->val] > depths[start->val]) {
    TreeNode* parent = parents[dest->val];
    if (parent->left && parent->left->val == dest->val) {
      destToLCA += "L";
    } else if (parent->right && parent->right->val == dest->val) {
      destToLCA += "R";
    }
    dest = parents[dest->val];
  }

  // move one by one
  while (start->val != dest->val) {
    startToLCA += "U";

    TreeNode* parent = parents[dest->val];
    if (parent->left && parent->left->val == dest->val) {
      destToLCA += "L";
    } else if (parent->right && parent->right->val == dest->val) {
      destToLCA += "R";
    }

    start = parents[start->val];
    dest = parents[dest->val];
  }

  reverse(destToLCA.begin(), destToLCA.end());
  string answer = startToLCA + destToLCA;
  return answer;
}
```

## 고생한 점
