# 1261. Find Elements in a Contaminated Binary Tree

[링크](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N이라 하자.

모든 노드를 순회하며 가능한 값들을 미리 저장할 수 있다.

이에 DFS를 사용할 경우 O(N)의 시간 복잡도가 소요된다. 해당 값을 hash set에 저장할 경우 O(1)의 시간 복잡도로 값을 찾을 수 있다.

### 공간 복잡도

모든 노드의 값을 저장할 경우 O(N)의 공간 복잡도가 필요하다.

### DFS & hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

입력받은 트리를 순회하며 해당 노드에 할당하는 값들을 hash set에 저장한다.

이후 쿼리마다 해당 값이 hash set에 존재하는지 확인한다.

```cpp
class FindElements {
 private:
  unordered_set<int> us;

  void recursive(TreeNode *node, int cur) {
    us.insert(cur);

    if (node->left) {
      recursive(node->left, cur * 2 + 1);
    }
    if (node->right) {
      recursive(node->right, cur * 2 + 2);
    }
  }

 public:
  FindElements(TreeNode *root) { recursive(root, 0); }

  bool find(int target) { return us.count(target) > 0; }
};
```

## 고생한 점
