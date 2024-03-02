# 1609. Even Odd Tree

[링크](https://leetcode.com/problems/even-odd-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

트리를 루트에서 부터 depth 별로 순회하기 위해 BFS를 사용한다.

이 때 depth가 짝수, 홀수인지 여부에 따라 각 값들이 유효한지 판단해야 한다.

이 순회에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

BFS에 O(N)의 공간 복잡도가 필요하다.

### BFS by step

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     199      |    O(N)     |    O(N)     |

루트 노드에서 부터 BFS 순회를 진행한다.

이 때 각 노드의 depth별로 순회를 진행하며 depth가 짝수, 홀수인지 여부에 따라 판단식을 다르게 진행한다.

```cpp
bool isEvenOddTree(TreeNode *root) {
  queue<TreeNode *> q;
  if (root) q.push(root);

  int step = 0;
  while (!q.empty()) {
    int size = q.size();

    bool isEven = step % 2 == 0;
    int before = isEven ? INT_MIN : INT_MAX;

    while (size--) {
      TreeNode *cur = q.front();
      q.pop();

      int num = cur->val;
      if (isEven) {
        if (num % 2 == 0) return false;
        if (before >= num) return false;
      } else {
        if (num % 2 == 1) return false;
        if (before <= num) return false;
      }
      before = num;

      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }

    step++;
  }

  return true;
}
```

## 고생한 점
