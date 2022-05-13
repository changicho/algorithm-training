# 2265. Count Nodes Equal to Average of Subtree

[링크](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N, 높이를 H라 하자.

모든 노드를 순회해야 하므로 최소 O(N)의 시간 복잡도를 사용한다.

재귀 호출을 이용해 각 노드에서 자식노드들의 합, 갯수를 call stack을 이용해 반환받으며 계산을 수행할 수 있다.

이 경우 노드를 순회함과 동시에 계산이 가능하므로 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

재귀 호출을 사용할 경우 call stack에 최대 O(H)의 공간 복잡도를 사용한다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(N)     |    O(H)     |

각 노드들을 후위순회로 순회하며 각 자식노드들에 대한 sum, 자식노드의 갯수를 받아온다.

즉 재귀호출중에 자기자신을 root로 하는 subTree의 total sum, total size를 반환한다.

이를 구현하면 다음과 같다.

```cpp
struct Status {
  int sum, count;
};
int equalCount = 0;

Status recursive(TreeNode *node) {
  Status cur = {node->val, 1};

  if (node->left) {
    Status left = recursive(node->left);

    cur.sum += left.sum;
    cur.count += left.count;
  }
  if (node->right) {
    Status right = recursive(node->right);

    cur.sum += right.sum;
    cur.count += right.count;
  }

  if (node->val == cur.sum / cur.count) {
    equalCount++;
  }

  return cur;
}

int averageOfSubtree(TreeNode *root) {
  if (root) recursive(root);

  return equalCount;
}
```

## 고생한 점
