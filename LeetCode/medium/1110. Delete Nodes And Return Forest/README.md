# 1110. Delete Nodes And Return Forest

[링크](https://leetcode.com/problems/delete-nodes-and-return-forest/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 개수를 N이라 하자.

모든 노드를 한번씩 방문해야 하므로 outer 시간 복잡도는 O(N)이다.

내부적으로 지워야할 노드인지 빠르게 판별하기 위해 hash_set을 사용할 수 있다. 이 경우 inner시간 복잡도는 O(1)이다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

DFS, BFS를 이용해 노드를 방문할경우 공간 복잡도는 O(N)이다.

hash_set을 이용해 지워야할 노드를 저장하는 경우에도 O(N)의 공간 복잡도가 필요하다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      32      |    O(N)     |    O(N)     |

BFS를 이용해 탐색하며 자식이 지워야할 노드인 경우, 지운 노드 hash set에 자식을 추가한 뒤 자식을 NULL로 바꾼다.

이는 계층 구조이기 때문에 서브트리들의 루트가 될 가능성은 지워진 자식의 자식들만 이기 때문이다.

이후 지워진 노드들의 자식노드들을 순회하며 서브트리의 루트가 될 수 있는경우 정답에 추가한다.

```cpp
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
  // 0. 전처리
  // 지운 노드들을 저장할 해시
  unordered_set<TreeNode*> removed_hash;
  unordered_set<int> hash_delete;
  // 지워야 할 노드를 빨리 찾기 위해 hash set으로 변경함
  for (int val : to_delete) {
    hash_delete.insert(val);
  }

  // 1. BFS를 이용해 순회하며
  // 자식만 비교하는 구조이므로 루트가 지워지는 경우 edge케이스 처리
  queue<TreeNode*> q;

  TreeNode* dummy = new TreeNode();
  dummy->left = root;

  q.push(dummy);

  while (!q.empty()) {
    TreeNode* cur = q.front();
    q.pop();

    // 2. 자식이 지워야할 노드인 경우, 지운 노드 hash set에 자식을 추가한 뒤 자식을 NULL로 바꿈
    // 이는 계층 구조이기 때문에 서브트리들의 루트가 될 가능성은 지워진 자식의 자식들만 이기 때문
    if (cur->left) {
      q.push(cur->left);
      // 지워야 하는 경우
      if (hash_delete.count(cur->left->val) > 0) {
        removed_hash.insert(cur->left);
        cur->left = NULL;
      }
    }
    if (cur->right) {
      q.push(cur->right);

      // 지워야 하는 경우
      if (hash_delete.count(cur->right->val) > 0) {
        removed_hash.insert(cur->right);
        cur->right = NULL;
      }
    }
  }

  // 3. 지운 자식 노드 hash set을 순회하며 서브트리의 루트가 될 수 있는경우 루트로 설정
  // 루트의 경우 edge 케이스 처리
  vector<TreeNode*> answer;
  if (removed_hash.count(root) == 0) answer.push_back(root);
  for (TreeNode* removed : removed_hash) {
    if (removed->left && removed_hash.count(removed->left) == 0) answer.push_back(removed->left);
    if (removed->right && removed_hash.count(removed->right) == 0) answer.push_back(removed->right);
  }

  return answer;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(N)     |

postOrder를 이용해 자식들을 먼저 방문하고, 이를 갱신한다.

postOrder 순으로 방문하기 때문에 자신이 루트노드인 서브트리에서 노드들이 다 삭제되어 있음이 보장된다.

따라서 현재 노드가 삭제된 경우, 자식 노드가 남아있다면 서브트리의 루트 노드로 설정한다.

이 때 포인터를 레퍼런스로 넘겨 자체로 수정할 수 있도록 한다.

```cpp
void recursive(TreeNode*& root, vector<TreeNode*>& answer, unordered_set<int>& hash_delete) {
  if (!root) return;

  recursive(root->left, answer, hash_delete);
  recursive(root->right, answer, hash_delete);

  if (hash_delete.count(root->val) > 0) {
    if (root->left) answer.push_back(root->left);
    if (root->right) answer.push_back(root->right);
    root = NULL;
    delete root;
  }
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
  vector<TreeNode*> answer;
  unordered_set<int> hash_delete;

  for (int id : to_delete) {
    hash_delete.insert(id);
  }

  if (root && hash_delete.count(root->val) == 0) answer.push_back(root);
  recursive(root, answer, hash_delete);

  return answer;
}
```

## 고생한 점
