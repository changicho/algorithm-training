# 1382. Balance a Binary Search Tree

[링크](https://leetcode.com/problems/balance-a-binary-search-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

각 노드를 중위 순회해 값들을 배열에 저장하고, 이를 이용해 균형 이진 탐색 트리를 만들 수 있다.

이 경우 중위 순회에 O(N), 재귀 호출에 O(N)의 시간 복잡도가 소요되므로 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

재귀 호출할 경우 call stack에 O(N)의 공간 복잡도가 필요하다.

### 중위 순회 & 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      92      |    O(N)     |    O(N)     |

트리를 중위 순회해 값을 오름차순으로 정렬된 배열을 만든다.

이 배열을 이용해 균형 이진 탐색 트리를 만든다.

이 때 각 단계마다 범위에서 중앙값을 선택한 뒤 이를 subTree의 root로 설정한 뒤 왼쪽, 오른쪽 부분으로 나눠 재귀 호출한다.

```cpp
void getVals(TreeNode *node, vector<int> &vals) {
  if (!node) return;

  getVals(node->left, vals);
  vals.push_back(node->val);
  getVals(node->right, vals);
}

TreeNode *recursive(int left, int right, vector<int> &vals) {
  if (left > right) return NULL;
  if (left == right) {
    return new TreeNode(vals[left]);
  }

  int mid = left + (right - left) / 2;

  TreeNode *node = new TreeNode(vals[mid]);
  node->left = recursive(left, mid - 1, vals);
  node->right = recursive(mid + 1, right, vals);

  return node;
}

TreeNode *balanceBST(TreeNode *root) {
  vector<int> vals;

  getVals(root, vals);

  return recursive(0, vals.size() - 1, vals);
}
```


## 고생한 점
