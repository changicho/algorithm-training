# 2196. Create Binary Tree From Descriptions

[링크](https://leetcode.com/problems/create-binary-tree-from-descriptions/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

descriptions의 크기를 N이라 하자.

노드의 갯수는 최대 N-1개까지 가능하다. (description에 정의되며 BST를 구성해야 하므로)

각 노드들을 순회하며 자식노드를 이어붙이고, 맨 마지막에 부모 노드가 없는 루트노드를 반환한다.

이 때 hash map을 사용할 경우 각 노드에 접근하는데 O(1)의 시간 복잡도로 가능하다.

이를 모든 노드에 대해 순회할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1067     |    O(N)     |    O(N)     |

각 노드의 숫자는 unique한것을 이용한다.

각 노드별로 빠르게 찾기 위해 hash map을 사용한다.

이 때 각 노드의 부모 노드를 찾기위한 hash map또한 생성한다.

이후 각 노드의 연결 관계를 이어주고 맨 마지막에 root노드를 찾는다.

```cpp
TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
  TreeNode* root;

  unordered_map<int, TreeNode*> valToNode;
  unordered_map<int, int> parents;

  for (vector<int>& d : descriptions) {
    int p = d[0], c = d[1];
    bool isLeft = d[2] == 1;

    if (!valToNode[p]) valToNode[p] = new TreeNode(p);
    if (!valToNode[c]) valToNode[c] = new TreeNode(c);

    parents[c] = p;
    if (isLeft) {
      valToNode[p]->left = valToNode[c];
    } else {
      valToNode[p]->right = valToNode[c];
    }
  }

  for (auto it : valToNode) {
    if (parents.count(it.first) == 0) {
      root = valToNode[it.first];
      break;
    }
  }

  return root;
}
```

## 고생한 점
