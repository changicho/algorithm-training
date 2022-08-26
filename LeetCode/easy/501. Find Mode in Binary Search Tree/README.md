# 501. Find Mode in Binary Search Tree

[링크](https://leetcode.com/problems/find-mode-in-binary-search-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자.

모든 노드를 순회하며 값을 count하고 이중 가장 많이 나타나는 값을 반환할 수 있다.

이 경우 순회에 O(N), count 후 정답을 구하는데 O(N)의 시간 복잡도가 사용된다.

### 공간 복잡도

DFS를 수행하는데 O(N)의 공간 복잡도를 사용한다.

count를 하는 공간을 만들 경우 O(N)의 공간 복잡도를 사용한다.

정답 배열에 최대 O(N)의 공간 복잡도를 사용한다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |    O(N)     |    O(N)     |

트리의 노드를 모두 탐색한다.

이 과정에서 값들을 count하고 가장 높은 빈도수를 갱신한다.

이 가장 높은 빈도수를 가지는 값을 모두 반환한다.

```cpp
void recursive(TreeNode *node, unordered_map<int, int> &counts) {
  if (!node) return;

  counts[node->val]++;

  if (node->left) recursive(node->left, counts);
  if (node->right) recursive(node->right, counts);
}

vector<int> findMode(TreeNode *root) {
  unordered_map<int, int> counts;

  recursive(root, counts);

  int maximum = 0;
  for (auto &it : counts) {
    int key = it.first, val = it.second;
    maximum = max(maximum, val);
  }

  vector<int> answer;
  for (auto &it : counts) {
    int key = it.first, val = it.second;

    if (val == maximum) {
      answer.push_back(key);
    }
  }
  return answer;
}
```

### 중위 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(N)     |    O(N)     |

원소들은 중복되어있더라고, BST기반으로 배치되어있다.

- 왼쪽 : 현재값보다 같거나 작은값들 위치
- 오른쪽 : 현재값보다 같거나 큰값들 위치

따라서 중위 순회를 이용해 같은 값들을 연이어 순회할 수 있다.

이는 같은 값들의 갯수를 연속해서 탐색할 수 있음을 의미하므로 count하는 배열을 생성하지 않아도 된다.

따라서 count와 동시에 정답배열을 갱신할 수 있다.

이를 구현하면 다음과 같다.

```cpp
int maximum = 0, curCount = 0, curVal = INT_MIN;
vector<int> answer;

void inOrder(TreeNode *root) {
  if (root == NULL) return;

  inOrder(root->left);
  if (curVal == root->val) {
    curCount++;
  } else {
    curCount = 1;
  }

  if (curCount > maximum) {
    answer.clear();
    maximum = curCount;
    answer.push_back(root->val);
  } else if (curCount == maximum) {
    answer.push_back(root->val);
  }
  curVal = root->val;
  inOrder(root->right);
}

vector<int> findMode(TreeNode *root) {
  inOrder(root);

  return answer;
}
```


## 고생한 점
