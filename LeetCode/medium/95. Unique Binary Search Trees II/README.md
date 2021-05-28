# 95. Unique Binary Search Trees II

[링크](https://leetcode.com/problems/unique-binary-search-trees-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

N개의 숫자를 어떤 순서로 집어넣는지에 따라서 트리의 모양이 결정된다.

N은 최대 8이며 모든 경우를 탐색할 경우 8!이므로 탐색에 O(40,320)가 소요된다.

이를 트리로 만드는데 O(N \* log_2(N))의 시간 복잡도가 소요되며 이는 최종적으로 O(N! \* N \* log_2(N))가 된다.

모든 경우를 탐색할 경우 중복된 경우가 매우 많으므로 중복에 대한 처리를 수행해줘야 한다.

혹은 재귀호출을 이용한 동적 계획법(top-down)으로 문제를 풀이할 수 도 있다.

이진 탐색 트리이므로 head의 왼쪽의 자식들은 자신보다 무조건 작고, head의 오른쪽 자식노드들은 자신보다 크다는 것이 보장된다.

따라서 현재 subTree에 포함될 숫자의 범위에 해당하는 문제로 변경이 가능하다.

이 경우 시간 복잡도는 O(N \* N^2)이다.

### 공간 복잡도

모든 경우를 탐색할 경우 트리로 변환하는 데 O(2^N) 크기의 공간이 필요하다. 이는 배열로 트리의 관계를 나타내서 중복을 제거하고, 트리를 생성하기 위함이다.

재귀호출을 이용한 동적 계획법을 사용할 경우 O(N^2) 크기 만큼의 공간이 필요하다.

### 브루트 포스

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     280      | O(N! \* N \* log_2(N)) |   O(2^N)    |

1부터 8까지 이진탐색 트리에 집어넣는 순서를 모두 탐색한 뒤에

중복 여부를 체크하고 실제 이진 트리를 생성한다.

```cpp
vector<TreeNode*> generateTrees(int n) {
  vector<TreeNode*> answer;
  set<vector<int>> s;

  vector<int> array(n);
  for (int i = 0; i < n; i++) {
    array[i] = i + 1;
  }

  do {
    vector<int> tree(1000, 0);

    for (int num : array) {
      push(tree, num);
    }

    if (s.find(tree) != s.end()) continue;
    s.insert(tree);

    TreeNode* cur = convert(tree, n);

    answer.push_back(cur);
  } while (next_permutation(array.begin(), array.end()));

  return answer;
}

void push(vector<int>& tree, int num) {
  int index = 1;

  while (tree[index] != 0) {
    if (tree[index] < num) {
      index = index * 2 + 1;
    } else {
      index = index * 2;
    }
  }

  tree[index] = num;
}

TreeNode* convert(vector<int>& array, int limit) {
  vector<TreeNode*> nodes(array.size(), NULL);
  TreeNode* head = new TreeNode(array[1]);
  nodes[1] = head;

  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    int i = q.front();
    q.pop();

    int left = i * 2;
    int right = i * 2 + 1;

    if (left >= array.size()) continue;

    if (array[left] != 0) {
      nodes[left] = new TreeNode(array[left]);
      nodes[i]->left = nodes[left];
      q.push(left);
    }
    if (array[right] != 0) {
      nodes[right] = new TreeNode(array[right]);
      nodes[i]->right = nodes[right];
      q.push(right);
    }
  }

  return head;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      | O(N \* N^2) |   O(N^2)    |

현재 범위에서 순회하며 head를 지정하고 head 이전 범위와 head 다음 범위에 대해서 subTree들을 만든다.

이후 이 subTree들에 대해서 반복문을 수행해 현재 숫자가 head인 경우의 모든 이진트리를 생성한다.

현재 head에 따른 이진 트리를 탐색할 때 이미 head는 정해져 있으므로 중복된 경우는 발생하지 않는다.

```cpp
vector<TreeNode*> dp[9][9];

vector<TreeNode*> generateTrees(int n) {
  return generateSubTrees(1, n);
}

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
```

## 고생한 점
