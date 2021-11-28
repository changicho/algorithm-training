# 146. LRU Cache

[링크](https://leetcode.com/problems/lru-cache/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

저장 가능한 자료의 개수를 N이라 하자.

put 연산과 get 연산을 O(1)의 시간복잡도로 구현해야 한다.

이를 위해 링크드 리스트 (우선순위 + 연결관계)와 hash map을 이용해 구현한다.

LRU cache에서 우선순위가 낮은 데이터는 링크드 리스트에서 가장 뒤에 있는 노드이며 삭제가 필요할 때 이를 삭제한다.

우선순위를 높일 노드의 경우 맨 앞으로 이동시킨다.

해당 노드들을 빨리 검색하기 위해 hash map을 이용한다.

### 공간 복잡도

각 노드들을 저장할 hash map과 링크드 리스트에 O(N)의 공간 복잡도를 각각 사용한다.

따라서 O(N)의 공간 복잡도를 사용한다.

### hash map + linked list

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     444      |    O(1)     |    O(N)     |

최대 저장 가능한 자료의 개수를 N이라 하자.

링크드 리스트를 이용해 우선순위 관계를 표현한다.

또한 각 링크드 리스트의 노드에 빨리 접근하기 위해 N만큼의 크기를 가지는 해시 맵을 이용한다.

연결 리스트를 구현하기 위해서 다음과 같은 노드를 사용한다.

```cpp
struct Node {
  int key, val;
  Node *prev, *next;

  Node() {}
  Node(int key, int val) {
    this->key = key;
    this->val = val;
  }
};
```

링크드 리스트를 구현하기 위해 다음 자료구조들을 선언한다.

- hash map : key : key값, value : Node\*
- head, tail Node : 링크드 리스트의 맨 앞과 맨 뒤를 저장할 노드
- size : 저장 가능한 최대 크기

head와 tail은 빈 노드이며 링크드 리스트에서 제일 앞의 노드는 head.next, 제일 뒤의 노드는 tail.prev로 참조한다.

초기상태에서 size와 head, tail의 연결 구조를 갱신한다.

삽입 연산은 다음과 같다.

1. 만약 key에 해당하는 값이 hash map에 이미 있는 경우 이를 삭제한다.
2. 새 노드를 만들고 hash map에 저장한다.
3. 노드를 맨 앞에 삽입한다.
4. 만약 최대 크기를 넘엇을 경우 맨 뒤의 노드를 삭제한다.

검색 연산은 다음과 같다.

1. 만약 hash map에 key에 해당하는 값이 없으면 -1을 반환한다.
2. 노드를 찾은 뒤 반환할 데이터로 노드의 value를 저장한다.
3. 노드를 맨 앞으로 이동해준다.

노드를 맨 앞으로 이동하는 부분은 다음 2가지 파트로 구현한다.

1. 해당 노드의 원래 연결 구조를 삭제한다.
2. 이동할 노드를 head->next로 이동한다.

이를 구현하면 다음과 같다.

```cpp
class LRUCache {
 private:
  unordered_map<int, Node*> hashMapToNode;
  Node *head = new Node(), *tail = new Node();
  int capacity;

  void cutTarget(Node* target) {
    Node *prev = target->prev, *next = target->next;
    prev->next = next;
    next->prev = prev;
  }

  void insertFront(Node* target) {
    Node* next = head->next;
    head->next = target;

    target->prev = head;
    target->next = next;

    next->prev = target;
  }

  void moveFirst(Node* target) {
    cutTarget(target);
    insertFront(target);
  }

 public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (hashMapToNode.find(key) == hashMapToNode.end()) return -1;

    Node* target = hashMapToNode[key];
    int ret = target->val;

    moveFirst(target);
    return ret;
  }

  void put(int key, int value) {
    if (hashMapToNode[key]) {
      Node* target = hashMapToNode[key];
      cutTarget(target);
      hashMapToNode.erase(key);
      delete target;
    }

    Node* node = new Node(key, value);
    hashMapToNode[key] = node;
    insertFront(node);

    // delete part
    if (hashMapToNode.size() > capacity) {
      // delete tail
      Node* target = tail->prev;
      cutTarget(target);
      hashMapToNode.erase(target->key);
      delete target;
    }
  }
};
```

## 고생한 점
