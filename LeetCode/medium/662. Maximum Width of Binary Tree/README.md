# 662. Maximum Width of Binary Tree

[링크](https://leetcode.com/problems/maximum-width-of-binary-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자.

width를 구하기 위해 각 노드에 1부터 시작하는 id를 붙여 풀이한다.

이 때 id는 child로 넘어갈 때 (id \* 2), (id \* 2 + 1)로 설정하며, 최대 2^N까지 커질 수 있다.

이 경우 모든 노드를 순회하며 각 level의 가장 왼쪽 노드의 id와 오른쪽 노드의 id를 찾을 수있다. 이 차이를 이용해 width를 구한다.

이 경우 모든 노드를 한번 순회하며 풀이할 수 있으므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

id는 최대 2^N까지 커질 수 있다. 이때 overflow가 일어날 수 있으므로 unsigned형으로 사용한다.

DFS를 이용할 경우 O(N), BFS를 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

루트의 id를 1로 설정하고 자식 노드의 id를 2, 3으로 설정한다.

즉 다음과 같은 규칙으로 id들을 설정한다.

- id
- left child : id \* 2
- right child : id \* 2 + 1

이 경우 같은 level에서 최대 width는 가장 왼쪽 id와 오른쪽 id의 차이가 된다.

```javascript
// 각 level별 id
[1];
[2, 3];
[4, 5, 6, 7];
[8, 9, 10, 11, 12, 13, 14, 15];
```

BFS를 이용해 각 level별로 순회한다.

이 때 담을 데이터는 다음과 같다.

```cpp
struct Status {
  TreeNode *node;
  unsigned int x;
};
```

이 경우 같은 level의 leftMost, rightMost인 id를 구할 수 있다.

두 id의 차이 + 1이 width이므로 이를 이용해 정답을 갱신한다.

이 때 overflow가 발생할 수 있으므로 이를 주의한다.

```cpp
int widthOfBinaryTree(TreeNode *root) {
  int answer = 0;

  queue<Status> q;
  if (root) q.push({root, 1});

  while (!q.empty()) {
    int size = q.size();
    unsigned int left = q.front().x, right = q.front().x;

    while (size--) {
      Status cur = q.front();
      q.pop();

      right = cur.x;

      if (cur.node->left) q.push({cur.node->left, cur.x * 2});
      if (cur.node->right) q.push({cur.node->right, cur.x * 2 + 1});
    }

    answer = max(answer, (int)(right - left + 1));
  }

  return answer;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

DFS를 이용해 왼쪽노드부터 우선 순회한다.

이를 이용해 각 level의 leftMost id들을 배열에 저장한다.

이후 탐색을 진행하며 현재 id와 해당 level의 leftMost id의 차이를 이용해 width를 구한다.

```cpp
vector<int> lefts;  // [depth] = leftMostId

int dfs(TreeNode *node, unsigned int id, int level) {
  if (!node) return 0;
  if (level >= lefts.size()) lefts.push_back(id);  // add left most node

  int fromLeft = 0, fromRight = 0, current = id + 1 - lefts[level];

  if (node->left) fromLeft = dfs(node->left, id * 2, level + 1);
  if (node->right) fromRight = dfs(node->right, id * 2 + 1, level + 1);

  return max({current, fromLeft, fromRight});
}

int widthOfBinaryTree(TreeNode *root) {
  int answer = dfs(root, 1, 0);

  return answer;
}
```

## 고생한 점

2배씩 증가시키는 과정에서 overflow가 발생했다. 이를 위해 unsigned형태를 사용함.
