# 109. Convert Sorted List to Binary Search Tree

[링크](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 노드의 개수를 N이라 하자.

모든 노드를 한번씩 방문해야 하므로 outer 시간 복잡도는 O(N)이다.

BST를 구성하면 되기 때문에 range에서 중앙에 위치한 값을 찾아 range를 분리해 탐색해야한다.

중앙에 위치한 값을 연결 리스트에서 직접 찾는 경우 O(N)의 시간 복잡도가 소요된다.

이를 미리 vector로 바꾸는 경우 O(1)의 시간 복잡도가 소요된다.

두 방법 모두 내부적으로, 혹은 초기에 연결 리스트의 모든 원소를 한번 순회하기 때문에 이에 소요되는 시간 복잡도는 O(N)이다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

call stack에 쌓이는 횟수는 O(log_2(N))이다. (balanced BST를 만들기 때문에)

이 외에 vector를 이용할 경우 O(N)의 공간 복잡도가 필요하다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |   O(N^2)    | O(log_2(N)) |

inOrder순으로 방문한 연결 리스트가 주어지므로, 각 range마다 탐색을 이용해 풀이할 수 있다.

range의 mid값을 루트 노드로 가지는 서브트리를 만든다고 가정하다.

이후 left ~ mid, (mid + 1) ~ right까지 두 range를 만든다.

여기서 첫번째 left ~ mid는 left노드, (mid + 1) ~ right까지는 right노드로 설정한다.

예외 조건은 다음과 같다.

- 서브트리의 노드가 없는 경우 : left == right
- 서브트리의 노드가 하나인 경우 : left + 1 == right

이는 탐색에서 right는 끝값으로 설정하고 left ~ (right - 1) 까지의 노드로만 sub tree를 구성하기 때문이다.

연결 리스트의 구간에서 중앙을 찾는 로직은 토끼와 거북이 알고리즘을 이용한다.

이를 구현하면 다음과 같다.

```cpp
TreeNode *sortedListToBST(ListNode *head) {
  return recursive(head, NULL);
}

TreeNode *recursive(ListNode *left, ListNode *right) {
  if (left == right) return NULL;
  if (left->next == right) {
    TreeNode *root = new TreeNode(left->val);
    return root;
  }

  ListNode *mid = getMid(left, right);

  TreeNode *root = new TreeNode(mid->val);
  root->left = recursive(left, mid);
  root->right = recursive(mid->next, right);
  return root;
}

ListNode *getMid(ListNode *left, ListNode *right) {
  ListNode *slow = left, *fast = left;
  while (fast != right && fast->next != right) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
```

### 배열 사용

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |   O(N^2)    |    O(N)     |

위 방법과 동일하나, 미리 연결리스트를 배열로 만들고 중앙값을 찾는데 이를 이용한다.

```cpp
TreeNode *sortedListToBST(ListNode *head) {
  vector<int> array;
  ListNode *cur = head;

  while (cur) {
    array.push_back(cur->val);
    cur = cur->next;
  }

  int size = array.size();
  return recursive(array, 0, size);
}

TreeNode *recursive(vector<int> &array, int left, int right) {
  if (left == right) return NULL;
  if (left + 1 == right) {
    TreeNode *root = new TreeNode(array[left]);
    return root;
  }

  int mid = left + (right - left) / 2;

  TreeNode *root = new TreeNode(array[mid]);
  root->left = recursive(array, left, mid);
  root->right = recursive(array, mid + 1, right);
  return root;
}
```

## 고생한 점
