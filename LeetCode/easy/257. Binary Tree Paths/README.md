# 257. Binary Tree Paths

[링크](https://leetcode.com/problems/binary-tree-paths/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

모든 노드의 개수를 N이라하자.

모든 경로를 탐색하기 위해 노드를 모두 탐색해야 하므로 시간 복잡도는 O(N)이다.

내부적으로 각 경로마다 정답에 해당하는 format으로 변경하는 데 들어가는 시간 복잡도는 O(1)이다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

노드를 탐색하면서 path에 방문노드를 저장해야 한다.

path에는 최대 N개의 노드가 담길 수 있으므로 시간 복잡도는 O(N)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

DFS를 이용해 재귀적으로 노드를 탐색하고, 리프 노드에 도달한 경우 정답에 추가한다.

```cpp
vector<string> answer;

vector<string> binaryTreePaths(TreeNode *root) {
  vector<string> paths;
  recursive(root, paths);

  return answer;
}

void recursive(TreeNode *node, vector<string> paths) {
  if (!node) return;

  string val = to_string(node->val);
  paths.push_back(val);

  if (!node->left && !node->right) {
    answer.push_back(convert(paths));
    paths.pop_back();
    return;
  }

  if (node->left) recursive(node->left, paths);
  if (node->right) recursive(node->right, paths);

  paths.pop_back();
}

string convert(vector<string> &paths) {
  string ret = "";
  for (string s : paths) {
    ret += s + "->";
  }
  ret.erase(ret.length() - 2, 2);
  return ret;
}
```

## 고생한 점
