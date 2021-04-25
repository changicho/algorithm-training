# Merge two BST 's

[링크](https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

트리의 모든 요소를 최소한 한번은 순회해야 한다.

모든 트리 요소를 vector에 저장한 후 정렬할 경우 시간 복잡도는 O((N+M) \* log_2(N+M)) 이다.

트리를 inOrder로 순회한 후에 병합 정렬 방식으로 vector를 생성할 경우 시간 복잡도는 O(N + M) 이다.

### 공간 복잡도

vector에 저장후 정렬 시에는 별도의 공간이 필요하지 않다.

트리를 inOrder 순으로 조회 후 병합 정렬 방식을 이용할 경우 공간 복잡도는 O(N + M) 이다.

### 정렬

> 1.76s

|      시간 복잡도       | 공간 복잡도 |
| :--------------------: | :---------: |
| O((N+M) \* log_2(N+M)) |    O(1)     |

모든 트리를 순회하며 vector에 요소를 모두 저장한다.

이 vector를 정렬한다.

```cpp
vector<int> merge(Node *root1, Node *root2) {
  vector<int> arr;

  recursive(root1, arr);
  recursive(root2, arr);

  sort(arr.begin(), arr.end());

  return arr;
}

void recursive(Node *cur, vector<int> &arr) {
  if (!cur) return;

  arr.push_back(cur->data);

  recursive(cur->left, arr);
  recursive(cur->right, arr);
}
```

### inOrder

> 1.08s

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N + M)   |  O(N + M)   |

BST를 inOrder 순으로 순회할 경우 정렬된 상태로 노드를 방문하게 된다.

따라서 두 트리를 inOrder순으로 순회 후 각각 두 트리의 노드를 순서대로 방문한 vector 혹은 큐를 저장한다.

두 큐의 front를 비교하며 크기가 작은 순으로 vector에 삽입한다.

```cpp
vector<int> merge(Node *root1, Node *root2) {
  vector<int> arr;
  queue<int> first, second;

  inOrder(root1, first);
  inOrder(root2, second);

  while (!second.empty() && !first.empty()) {
    if (second.front() < first.front()) {
      arr.push_back(second.front());
      second.pop();
    } else {
      arr.push_back(first.front());
      first.pop();
    }
  }

  while (!first.empty()) {
    arr.push_back(first.front());
    first.pop();
  }

  while (!second.empty()) {
    arr.push_back(second.front());
    second.pop();
  }

  return arr;
}

void recursive(Node *cur, vector<int> &arr) {
  if (!cur) return;

  arr.push_back(cur->data);

  recursive(cur->left, arr);
  recursive(cur->right, arr);
}

void inOrder(Node *cur, queue<int> &q) {
  if (!cur) return;

  inOrder(cur->left, q);
  q.push(cur->data);
  inOrder(cur->right, q);
}
```

## 고생한 점
