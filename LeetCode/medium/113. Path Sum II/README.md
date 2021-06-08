# 113. Path Sum II

[링크](https://leetcode.com/problems/path-sum-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

path를 탐색하기 위해 모든 노드를 한번씩 방문해야 한다.

노드의 개수 N은 최대 5,000개이다.

따라서 시간 복잡도는 O(N)이다.

노드의 값에 음수또한 포함되므로 백 트래킹을 사용할 수 없다.

### 공간 복잡도

모든 경로로 탐색을 진행해봐야 한다. 따라서 O(N)만큼의 경우가 발생한다.

각 경우마다 path를 사용하며 경로의 방문 후 나갈 때 현재 방문한 값을 없애는 방법으로 하나의 공간을 사용할 수 있다.

따라서 공간 복잡도는 O(N)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

재귀 호출을 이용해 모든 경우를 탐색하며 정답인 경우를 판별한다.

노드의 값이 음수도 가능하므로 백트래킹을 사용할 수 없다.

따라서 모든 경우를 탐색한다.

이 때 path를 각 함수 호출마다 새로 생성하지 않고 기존 공간을 사용해 공간복잡도를 최적화한다.

```cpp
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
  vector<vector<int>> answers;
  vector<int> path;

  if (root) {
    path.push_back(root->val);
    recursive(answers, path, root, root->val, targetSum);
  }

  return answers;
}

void recursive(vector<vector<int>>& answers, vector<int>& path, TreeNode* node, int curSum, int target) {
  if (!node->left && !node->right) {
    if (curSum == target) answers.push_back(path);

    return;
  }

  if (node->left) {
    int value = node->left->val;
    path.push_back(value);
    recursive(answers, path, node->left, curSum + value, target);
    path.pop_back();
  }

  if (node->right) {
    int value = node->right->val;
    path.push_back(value);
    recursive(answers, path, node->right, curSum + value, target);
    path.pop_back();
  }
}
```

## 고생한 점
