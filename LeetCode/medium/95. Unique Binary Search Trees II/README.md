# 95. Unique Binary Search Trees II

[링크](https://leetcode.com/problems/unique-binary-search-trees-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

N개의 숫자를 어떤 순서로 집어넣는지에 따라서 트리의 모양이 결정된다.

x개의 노드로 이루어진 BST의 유일한 갯수를 Catalan number 라 한다. O(4^N / N^(3/2))

1부터 N까지의 Catalan number의 합을 M이라하자.

M을 구하는 데 들어가는 시간 복잡도는 O(4^N / sqrt(N)) 이다.

모든 경우를 탐색할 경우 중복된 경우가 매우 많으므로 중복에 대한 처리를 수행해줘야 한다.

재귀호출을 이용한 동적 계획법(top-down)으로 문제를 풀이할 수 도 있다.

이진 탐색 트리이므로 head의 왼쪽의 자식들은 자신보다 무조건 작고, head의 오른쪽 자식노드들은 자신보다 크다는 것이 보장된다.

따라서 현재 subTree에 포함될 숫자의 범위에 해당하는 문제로 변경이 가능하다.

### 공간 복잡도

동적 계획법에 사용하는 경우의 수에 O(2^N) 크기의 공간이 필요하다.

해당 공간 내부에 서브트리들이 들어가야 총 O(M)의 공간 복잡도를 사용한다. 이는 O(4^N / sqrt(N)) 이다.

### 동적 계획법 (top down)

| 내 코드 (ms) |   시간 복잡도    |   공간 복잡도    |
| :----------: | :--------------: | :--------------: |
|      7       | O(4^N / sqrt(N)) | O(4^N / sqrt(N)) |

현재 범위에서 순회하며 head를 지정하고 head 이전 범위와 head 다음 범위에 대해서 subTree들을 만든다.

이후 이 subTree들에 대해서 반복문을 수행해 현재 숫자가 head인 경우의 모든 이진트리를 생성한다.

현재 head에 따른 이진 트리를 탐색할 때 이미 head는 정해져 있으므로 중복된 경우는 발생하지 않는다.

```cpp
vector<TreeNode*> dp[9][9];

vector<TreeNode*> generateSubTrees(int from, int to) {
  if (from > to) return {NULL};
  if (from == to) return {new TreeNode(from)};
  if (!dp[from][to].empty()) return dp[from][to];
  vector<TreeNode*> res;

  vector<TreeNode*> leftSubTree, rightSubTree;

  for (int cur = from; cur <= to; cur++) {
    leftSubTree = generateSubTrees(from, cur - 1);
    rightSubTree = generateSubTrees(cur + 1, to);

    for (TreeNode* leftNode : leftSubTree) {
      for (TreeNode* rightNode : rightSubTree) {
        TreeNode* root = new TreeNode(cur);
        root->left = leftNode;
        root->right = rightNode;
        res.push_back(root);
      }
    }
  }
  dp[from][to] = res;
  return res;
}

vector<TreeNode*> generateTrees(int n) {
  return generateSubTrees(1, n);
}
```

## 고생한 점
