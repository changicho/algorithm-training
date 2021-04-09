# 111. Minimum Depth of Binary Tree

[링크](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

노드의 개수는 최대 10^5이다. 모든 노드를 탐색해야 하므로 시간 복잡도는 O(N) 이다.

### 공간 복잡도

최악의 경우 정답은 10^5이다.

### 재귀호출

현재 노드가 리프 노드인 경우에만 정답을 갱신해야한다.

```cpp
class Solution {
 public:
  int answer = 100001;
  int minDepth(TreeNode *root) {
    findDepth(root, 1);

    if (answer == 100001) answer = 0;
    return answer;
  }

  void findDepth(TreeNode *cur, int depth) {
    if (!cur) {
      return;
    }

    if (!cur->left && !cur->right) {
      answer = min(depth, answer);
      return;
    }

    findDepth(cur->left, depth + 1);
    findDepth(cur->right, depth + 1);
  }
};
```

## 정리

| 내 코드 (ms) |
| :----------: |
|              |

## 고생한 점
