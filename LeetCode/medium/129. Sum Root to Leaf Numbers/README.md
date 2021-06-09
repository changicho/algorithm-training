# 129. Sum Root to Leaf Numbers

[링크](https://leetcode.com/problems/sum-root-to-leaf-numbers/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자.

root에서 leaf까지 모든 경우를 순회해야한다. 따라서 모든 노드를 한번씩 방문해야 하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

모든 노드를 한번씩 방문하므로 콜 스택에 쌓이는 경우 공간 복잡도는 O(N)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

DFS를 통해 모든 노드를 탐색하며 leaf노드인 경우 정답에 더한다.

각 경우마다 현재의 sum을 인자로 넘긴다.

문제에서 트리의 depth는 10을 넘지 않는다. 이 경우 leaf노드까지 도달했을 때 자리수는 최대 10의 자리이다.

높이가 10일때 최대 2^10개의 leaf노드가 생길 수 있다. 이는 1024이며 자리수가 10인 수를 이만큼 더할 수 있다.

이때 자리수는 10^13이며 int형을 초과한다.

그러나 정답에서 반환하는 값이 int형 이므로 int형임이 보장된다고 판단한다.

```cpp
int answer = 0;

int sumNumbers(TreeNode *root) {
  recursive(root, 0);

  return answer;
}

void recursive(TreeNode *node, int sum) {
  if (!node) return;

  sum = sum * 10 + node->val;

  if (!node->left && !node->right) {
    answer += sum;
    return;
  }

  recursive(node->left, sum);
  recursive(node->right, sum);
}
```

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

BFS로 탐색하며 leaf노드에 도달하면 정답에 더한다.

```cpp
struct Status {
  TreeNode *node;
  int sum;
};

int sumNumbers(TreeNode *root) {
  int answer = 0;

  queue<Status> q;
  q.push({root, 0});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    TreeNode *node = cur.node;
    if (!node) continue;
    int sum = cur.sum * 10 + node->val;

    if (!node->left && !node->right) {
      answer += sum;
      continue;
    }

    q.push({node->left, sum});
    q.push({node->right, sum});
  }

  return answer;
}
```

## 고생한 점
