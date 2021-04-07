# 108. Convert Sorted Array to Binary Search Tree

[링크](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 원소의 개수는 최대 1,000개이다.

이를 결국 모두 탐색해야 하므로 시간 복잡도는 O(N)이다.

이 때 각 노드의 위치를 루트부터 찾는데 O(log(N))이 소요되므로 최종 시간 복잡도는 O(N \* log(N)) 이다.

### 공간 복잡도

노드의 값은 int형이며 연산시 이를 초과하지 않는다.

### 탐색의 순서

탐색의 순서는 다음과 같다.

start ~ end의 범위가 주어졌을 때, (start + end) / 2 값인 index를 방문하고 다시 범위를 두단계로 나누어 방문한다.

- start ~ (mid - 1)
- (mid + 1) ~ end

이는 주어진 배열은 오름차순이고, height-balanced를 생성할 때 서브트리의 노드의 차가 1 이하여야 하기 때문이다.

따라서 최대한 문제에서 요구하는데로 균형잡힌 트리를 생성해야 한다.

### DFS를 이용한 방법

> 12ms

재귀함수를 호출하며 현재 노드를 생성한다.

이 때 불가능한 경우엔 NULL을 채워넣는다.

```cpp
TreeNode* sortedArrayToBST(vector<int>& nums) {
  return sortedArrayToBST(nums, 0, nums.size() - 1);
}

TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
  if (start > end) return NULL;

  int mid = (start + end) / 2;
  TreeNode* root = new TreeNode(nums[mid]);

  root->left = sortedArrayToBST(nums, start, mid - 1);
  root->right = sortedArrayToBST(nums, mid + 1, end);

  return root;
}
```

### BFS를 이용한 방법

> 16ms

DFS와 동일하게 range를 이용하지만, 노드를 생성할 때 매번 루트에서부터 자신의 위치를 찾아야한다.

이진 탐색 트리를 생성하면 되므로 특정 기준에 맞춰 트리를 생성한다.

```cpp
TreeNode* sortedArrayToBST(vector<int>& nums) {
  int mid = (nums.size() - 1) / 2;
  TreeNode* root = new TreeNode(nums[mid]);

  queue<Range> q;
  q.push({0, mid - 1});
  q.push({mid + 1, (int)nums.size() - 1});

  while (!q.empty()) {
    Range cur = q.front();
    q.pop();

    if (cur.start > cur.end) continue;

    TreeNode* node = root;
    mid = (cur.start + cur.end) / 2;

    int val = nums[mid];
    while (true) {
      if (val < node->val) {
        if (!node->left) {
          node->left = new TreeNode(val);
          break;
        }
        node = node->left;
      } else {
        if (!node->right) {
          node->right = new TreeNode(val);
          break;
        }
        node = node->right;
      }
    }

    if (cur.start != cur.end) {
      q.push({cur.start, mid - 1});
      q.push({mid + 1, cur.end});
    }
  }

  return root;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|              |

## 고생한 점
