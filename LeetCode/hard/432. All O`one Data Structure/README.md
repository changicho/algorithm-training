# 432. All O`one Data Structure

[링크](https://leetcode.com/problems/all-oone-data-structure/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력되는 key들의 갯수를 N이라 하자.

hash map을 사용하는 경우 inc, dec에 O(1)의 시간 복잡도를 사용하며, min, max를 검색하는 데 O(N)의 시간 복잡도를 사용한다.

hash map과 연결 리스트를 사용할 경우 모든 연산에 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

연결 리스트와 hash map에 각각 O(N)의 공간 복잡도가 필요하다.

### hash map & linked list

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     103      |    O(1)     |    O(N)     |

각 key마다 현재 count를 저장하기 위해 hash map을 사용한다.

이 때 min, max를 빠르게 찾아야 한다.

각 count에 대해서 연결 리스트를 생성할 경우 head와 tail을 참조해 빠르게 min, max를 구할 수 있다.

이 때 increase, decrease를 할 때 count가 변경되는 경우에 대해서만 연결 리스트를 조작한다.

각 key들의 count가 연속되지 않을 수도 있음에 유의한다.

따라서 각 key마다 연결리스트 노드를 value로 갖는 hash map을 생성한다.

```cpp
class AllOne {
 private:
  struct Node {
    int count;
    Node* prev;
    Node* next;
    unordered_set<string> keys;

    Node(int count) : count(count), prev(nullptr), next(nullptr) {}
  };

  Node* head = new Node(0);
  Node* tail = new Node(0);
  unordered_map<string, Node*> um;

  Node* makeNode(int count, Node* prevNode, Node* nextNode) {
    Node* newNode = new Node(count);
    newNode->prev = prevNode;
    newNode->next = nextNode;
    prevNode->next = newNode;
    nextNode->prev = newNode;
    return newNode;
  }

  void removeNode(Node* node) {
    Node* prevNode = node->prev;
    Node* nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete node;
  }

 public:
  AllOne() {
    head->next = tail;
    tail->prev = head;
  }

  void inc(string key) {
    if (um.count(key) == 0) {
      Node* firstNode = head->next;

      if (firstNode == tail || firstNode->count > 1) {
        Node* newNode = makeNode(1, head, firstNode);
        firstNode = newNode;
      }

      firstNode->keys.insert(key);
      um[key] = firstNode;
      return;
    }

    Node* node = um[key];
    int count = node->count;
    node->keys.erase(key);

    Node* nextNode = node->next;
    if (nextNode == tail || nextNode->count != count + 1) {
      Node* newNode = makeNode(count + 1, node, nextNode);

      nextNode = newNode;
    }

    nextNode->keys.insert(key);
    um[key] = nextNode;

    if (node->keys.empty()) removeNode(node);
  }

  void dec(string key) {
    if (um.count(key) == 0) return;

    Node* node = um[key];
    node->keys.erase(key);
    int count = node->count;

    if (count == 1) {
      um.erase(key);
    } else {
      Node* prevNode = node->prev;

      if (prevNode == head || prevNode->count != count - 1) {
        Node* newNode = makeNode(count - 1, prevNode, node);
        prevNode = newNode;
      }

      prevNode->keys.insert(key);
      um[key] = prevNode;
    }

    if (node->keys.empty()) removeNode(node);
  }

  string getMaxKey() {
    if (tail->prev == head) return "";

    return *(tail->prev->keys.begin());
  }

  string getMinKey() {
    if (head->next == tail) return "";

    return *(head->next->keys.begin());
  }
};
```

## 고생한 점
