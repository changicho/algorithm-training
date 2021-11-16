# 652. Find Duplicate Subtrees

[링크](https://leetcode.com/problems/find-duplicate-subtrees/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 노드의 개수를 N이라 하자.

모든 노드를 한번씩 순회하며 해당 노드를 subTree의 root로 설정한 트리의 inOrder, preOrder, postOrder를 이용할 수 있다.

재귀 호출을 이용해 bottom up 방식으로 preOrder를 저장한다고 할 때, 현재 노드를 시작으로 하는 preOrder 순회한 값이 이전에 이미 나온 경우

해당 노드는 정답이 된다.

이 과정에서 모든 노드의 순회에 O(N)의 시간 복잡도를 사용한다.

내부적으로 경로의 저장은 hash map을 이용하므로 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 노드들의 preOrder경로를 저장하므로 O(N)의 공간 복잡도를 사용한다.

재귀호출 탐색에 O(N)의 공간 복잡도를 사용한다.

### preOrder

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(N)     |

트리의 root부터 preOrder순으로 순회하며 각 노드마다 preOrder값을 저장한다.

이후 현재 노드의 preOrder 값이 이전에 나온 경우 subTree가 같은 경우이므로 이를 정답에 추가한다.

여기서 preOrder순으로 순회할 때 다른 subTree인데도 preOrder가 같게 나올 수 있으므로 left part와 right part, data part를 별도의 문자열로 구분해 섞이지 않도록 구성한다.

subTree가 같은 경우 중 하나의 root 노드만 정답에 추가하면 되므로 별도의 hash map으로 중복을 제거한다.

preOrder값이 이전에 나왔는지 판별하기 위해 hash set을 사용한다.

```cpp
unordered_set<string> preOrders;
unordered_map<string, TreeNode *> um;

string doPreOrder(TreeNode *node) {
  string ret = "(D";
  ret += to_string(node->val);

  if (node->left) ret += "L" + doPreOrder(node->left);
  if (node->right) ret += "R" + doPreOrder(node->right);
  ret += ")";

  if (preOrders.count(ret) > 0 && !um[ret]) {
    um[ret] = node;
  } else {
    preOrders.insert(ret);
  }

  return ret;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
  vector<TreeNode *> answer;
  if (!root) return answer;

  doPreOrder(root);

  for (auto &it : um) {
    answer.push_back(it.second);
  }

  return answer;
}
```

## 고생한 점
