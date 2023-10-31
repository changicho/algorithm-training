# 1361. Validate Binary Tree Nodes

[링크](https://leetcode.com/problems/validate-binary-tree-nodes/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

DFS로 순회할 경우 valid한 트리의 경우 이전에 방문한 노드를 다시 방문하지 않는다.

이를 이용해 모든 노드가 하나의 루트를 가지는지, valid한지를 판별할 수 있다.

이 경우 O(N)의 공간 복잡도를 사용한다.

### 공간 복잡도

방문 여부에 O(N)의 공간 복잡도를 사용한다. DFS에 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      50      |    O(N)     |    O(N)     |

트리의 루트를 찾는다. 루트의 경우 leftChild, rightChild에서 나오지 않은 노드이다.

이후 루트를 시작점으로 DFS를 수행한다. 이 때 이미 방문한 노드를 다시 방문하는 경우 트리 구조가 아니게 된다.

이후 방문한 노드의 수가 전체 노드의 수인지 검사한다.

```cpp
bool visited[10001] = {
    false,
};

bool hasCycle = false;

int findRoot(int n, vector<int>& left, vector<int>& right) {
  unordered_set<int> children;
  children.insert(left.begin(), left.end());
  children.insert(right.begin(), right.end());

  int ret = -1;
  for (int node = 0; node < n; node++) {
    if (children.count(node) == 0) {
      if (ret != -1) return -1;
      ret = node;
    }
  }

  return ret;
}

void recursive(int node, vector<int>& leftChild, vector<int>& rightChild) {
  if (hasCycle) return;

  int children[] = {leftChild[node], rightChild[node]};
  for (int& child : children) {
    if (child == -1) continue;

    if (visited[child]) {
      hasCycle = true;
      return;
    }

    visited[child] = true;
    recursive(child, leftChild, rightChild);
  }
}

bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                              vector<int>& rightChild) {
  int root = findRoot(n, leftChild, rightChild);
  if (root == -1) return false;

  visited[root] = true;

  recursive(root, leftChild, rightChild);
  int count = 0;
  for (int node = 0; node < n; node++) {
    count += visited[node];
  }
  return !hasCycle && count == n;
}
```

## 고생한 점
