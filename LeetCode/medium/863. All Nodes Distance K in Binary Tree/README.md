# 863. All Nodes Distance K in Binary Tree

[링크](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N이라 하자.

트리를 그래프로 변경하는데 O(N)의 시간 복잡도를 사용하며, target부터 k거리에 있는 노드들을 찾는데 O(N)의 시간 복잡도가 소요된다.

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

그래프를 표현하는데 O(N)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(N)     |    O(N)     |

target노드에서 k거리에 있는 노드들을 찾을 때 다음 3가지 경우중 하나에 해당한다.

- left
- right
- parent

따라서 각 노드별로 부모노드의 위치를 저장해야 탐색이 가능하다.

따라서 각 노드들마다의 부모를 저장하는 hash map을 생성 후 target노드에서부터 k거리에 있는 노드들을 찾는다.

```cpp
unordered_map<TreeNode*, TreeNode*> parents;
unordered_map<TreeNode*, int> distances;

void setParents(TreeNode* node) {
  if (node->left) {
    parents[node->left] = node;
    setParents(node->left);
  }
  if (node->right) {
    parents[node->right] = node;
    setParents(node->right);
  }
}

void setParents(TreeNode* node, int dist) {
  distances[node] = dist;

  if (node->left && !distances.count(node->left)) {
    setParents(node->left, dist + 1);
  }
  if (node->right && !distances.count(node->right)) {
    setParents(node->right, dist + 1);
  }
  if (parents[node] && !distances.count(parents[node])) {
    setParents(parents[node], dist + 1);
  }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
  setParents(root);
  setParents(target, 0);

  vector<int> answer;
  for (auto& it : distances) {
    TreeNode* node = it.first;
    int dist = it.second;

    if (dist == k) {
      answer.push_back(node->val);
    }
  }
  return answer;
}
```

## 고생한 점
