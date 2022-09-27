# 530. Minimum Absolute Difference in BST

[링크](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

중위 순회를 이용해 각 노드를 값에대한 오름차순으로 방문할 수 있다.

이 방문한 직전값과 현재값의 차이를 비교해 정답을 갱신한다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

트리를 순회하는데 O(N)의 공간 복잡도를 사용한다.

### 중위 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      41      |    O(N)     |    O(N)     |

중위순회로 트리를 방문한다.

이 경우 트리는 BST이므로 각 값을 오름차순으로 방문할 수 있다.

수를 방문할 때마다 배열에 삽입하고 직전 값과 비교해 차이중 가장 작은 값을 구한다.

```cpp
void recursive(TreeNode *node, vector<int> &nums) {
  if (!node) return;

  if (node->left) {
    recursive(node->left, nums);
  }
  nums.push_back(node->val);
  if (node->right) {
    recursive(node->right, nums);
  }
}

int getMinimumDifference(TreeNode *root) {
  int answer = 100001;

  vector<int> nums;
  recursive(root, nums);

  for (int i = 0; i < nums.size() - 1; i++) {
    answer = min(answer, abs(nums[i] - nums[i + 1]));
  }

  return answer;
}
```

## 고생한 점
