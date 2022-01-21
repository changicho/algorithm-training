# 938. Range Sum of BST

[링크](https://leetcode.com/problems/range-sum-of-bst/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자.

모든 노드를 순회하며 range이내의 값인 경우에만 정답에 더하면 sum을 구할 수 있다.

이 경우 모든 노드의 순회에 O(N)의 시간 복잡도를 사용한다.

backtracking을 이용해 유효한 경우만 탐색을 이어나갈 수 있다.

이 경우 또한 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

call stack에 최대 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     158      |    O(N)     |    O(N)     |

DFS로 노드들을 순회하며 range에 들어오는 경우만 정답에 더한다.

이 때 자식노드를 탐색할때 다음과 같은 경우는 탐색하지 않아도 된다.

- 현재 값이 low인 경우는 left를 탐색할 필요가 없다.
- 현재 값이 high인 경우는 right를 탐색할 필요가 없다.

위 두 경우는 현재 값이 range의 임계값인 경우이다.

따라서 재귀호출을 다음과 같이 구현할 수 있다.

```cpp
int answer = 0;

void recursive(TreeNode *root, int low, int high) {
  // case that value in range
  if (low <= root->val && root->val <= high) {
    answer += root->val;
  }

  // if children's value in range
  if (root->left && low < root->val) recursive(root->left, low, high);
  if (root->right && root->val < high) recursive(root->right, low, high);
}

int rangeSumBST(TreeNode *root, int low, int high) {
  if (root) recursive(root, low, high);

  return answer;
}
```

## 고생한 점
