# 1457. Pseudo-Palindromic Paths in a Binary Tree

[링크](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

루트에서 부터 리프까지 경로를 순회하는 데 O(N)의 시간 복잡도가 필요하다.

이후 해당 경로에 대해서 팰린드롬을 만들 수 있는지 판단해야 한다.

모든 path를 직접 비교할 경우 O(N)의 시간 복잡도를 사용하며 총 시간 복잡도는 O(N^2)이다. 이는 제한시간 내에 불가능하다.

노드의 값의 범위가 한정되어 있으므로 count배열을 이용해 팰린드롬을 판별할 수 있다.

이 경우 O(1)의 시간 복잡도로 팰린드롬을 판별할 수 있다. 따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

DFS 순회에 O(N)의 공간 복잡도가 필요하다.

count 배열에 O(1)의 공간 복잡도가 필요하다.

### DFS & count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     245      |    O(N)     |    O(1)     |

DFS를 이용해 루트에서부터 리프까지 모든 경로를 순회한다.

이 때 각 노드들의 값이 나타난 빈도를 count에 저장한다.

리프노드에서 count를 이용해 팰린드롬을 판별한다.

- count의 원소의 수가 모두 짝수인 경우 팰린드롬이다.
- count의 원소의 수가 홀수인 경우 한개의 원소만 홀수여야 한다.

이를 이용해 정답을 갱신한다.

```cpp
int answer = 0;

bool check(vector<int> &counts) {
  int odds = 0;
  for (int &num : counts) {
    if (num % 2 == 1) {
      odds++;
    }
  }

  if (odds < 2) return true;
  return false;
}

void recursive(TreeNode *node, vector<int> &counts) {
  bool isLeaf = true;

  if (node->left || node->right) isLeaf = false;

  if (isLeaf) {
    if (check(counts)) answer++;
    return;
  }

  if (node->left) {
    counts[node->left->val]++;
    recursive(node->left, counts);
    counts[node->left->val]--;
  }
  if (node->right) {
    counts[node->right->val]++;
    recursive(node->right, counts);
    counts[node->right->val]--;
  }
}

int pseudoPalindromicPaths(TreeNode *root) {
  if (!root) return 0;

  vector<int> counts(10);
  counts[root->val]++;

  recursive(root, counts);

  return answer;
}
```

## 고생한 점
