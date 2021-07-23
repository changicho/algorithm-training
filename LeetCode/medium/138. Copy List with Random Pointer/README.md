# 138. Copy List with Random Pointer

[링크](https://leetcode.com/problems/copy-list-with-random-pointer/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N이라 하자.

복사하기 위해선 결국 모든 노드들을 한번씩 방문해야한다.

따라서 outer 시간 복잡도는 O(N)이다.

내부적으로 random을 설정 하기 위해 hash map구조를 random 포인터에 대응하는 새로운 노드를 빠르게 찾을 수 있다.

inner 시간 복잡도는 O(1)이므로, 시간 복잡도는 O(N)이다.

혹은 각 노드들을 복사하고 바로 뒤에 붙여 순회해 풀이할 수 있다.

이 경우에도 시간 복잡도는 O(N)이다.

### 공간 복잡도

hash map을 이용하는 경우 O(N)만큼의 공간 복잡도가 필요하다.

각 노드들을 copy한 노드를 next로 설정하고 복사하는 경우 별도의 공간이 필요하지 않다.

따라서 공간 복잡도는 O(1)이다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

각 노드를 key로하고 값으로 copy한 노드를 가지는 hash map을 생성한다.

이후 원본 링크드 리스트를 순회하며 노드들을 복사한 뒤, 복사한 노드들의 random을 설정한다.

```cpp
Node* copyRandomList(Node* head) {
  vector<Node*> array;
  unordered_map<Node*, Node*> m;

  Node* dummy = new Node(0);
  Node* before = dummy;
  Node* cur = head;

  // deep copy with dummy, and store to array and map
  while (cur) {
    Node* node = new Node(cur->val);
    before->next = node;
    array.push_back(node);
    m[cur] = node;

    cur = cur->next;
    before = before->next;
  }

  // set random of nodes in array
  cur = head;
  for (Node* node : array) {
    if (cur->random) {
      node->random = m[cur->random];
    } else {
      node->random = NULL;
    }
    cur = cur->next;
  }

  return dummy->next;
}
```

### 이어붙이기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

원본 링크드 리스트의 각 요소에 next에 자기 자신의 값을 가지는 노드를 새로 복사해 붙인다.

이 경우 복제한 요소들의 random값은 기존 random 포인터의 next 값이 된다. (복제된 random)

이를 이용해 복제한 요소 외의 공간 없이 deep copy를 수행할 수 있다.

```cpp
Node* copyRandomList(Node* head) {
  if (!head) return NULL;

  // second를 이용해 복제를 시작함
  Node *first, *second;
  for (first = head; first; first = first->next->next) {
    second = new Node(first->val);
    second->random = first->random;
    second->next = first->next;
    first->next = second;
  }

  // 반환할 복제된 list의 시작점을 설정
  Node* ret = head->next;

  // 복제한 링크드 리스트의 요소의 random을 설정
  for (first = head; first; first = first->next->next) {
    if (first->random) {
      first->next->random = first->random->next;
    }
  }

  // 복제한 링크드 리스트만을 연결시킴
  for (first = head; first; first = first->next) {
    second = first->next;
    first->next = second->next;

    if (second->next) {
      second->next = second->next->next;
    }
  }

  return ret;
}
```

## 고생한 점
