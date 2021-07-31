# 706. Design HashMap

[링크](https://leetcode.com/problems/design-hashmap/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

해시 맵의 모든 원소의 개수를 N이라 하자.

해시맵이므로 모든 연산은 O(1) 이내에 이루어져야 한다.

배열을 이용해 관리할 경우 O(1) 이내에 처리가 가능하다.

해시맵을 직접 구성할 경우 O(1) 이내에 처리가 가능하다.

### 공간 복잡도

key, value의 범위는 0 ~ 10^6 까지이다.

배열을 이용해 모든 공간을 관리할 경우 공간 복잡도는 O(10^6)이다.

해시맵을 직접 구성할 경우 이보다 작은 값에 구성할 수 있다.

### 배열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      88      |    O(1)     |    O(N)     |

모든 범위에 대해 배열을 미리 만들어 놓고 사용할 경우 O(1)의 시간 복잡도로 모든 연산이 가능하다.

```cpp
int data[1000001];
MyHashMap() {
  fill(data, data + 1000000, -1);
}

void put(int key, int value) {
  data[key] = value;
}

int get(int key) {
  return data[key];
}

void remove(int key) {
  data[key] = -1;
}
```

### 해시 맵

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     108      |    O(1)     |    O(N)     |

해시 함수를 이용해 해시 키를 생성하고, 해당 키에 이미 값이 있을 경우 연결리스트를 이용해 이어붙여 해시맵을 구성할 수 있다.

데이터를 저장하기 위해 다음과 같은 구조체를 정의한다.

```cpp
struct Node {
  int key, val;
  Node* next;

  Node(int k, int v, Node* n) {
    key = k;
    val = v;
    next = n;
  }
};

const static int size = 19997;
const static int mult = 12582917;

Node* data[size];

int hashFunction(int key) {
  return (int)((long)key * mult % size);
}
```

각 연산들을 다음과 같이 구성한다.

```cpp
void put(int key, int val) {
  remove(key);
  int hashValue = hashFunction(key);
  Node* node = new Node(key, val, data[hashValue]);

  data[hashValue] = node;
}

int get(int key) {
  int hashValue = hashFunction(key);
  Node* node = data[hashValue];

  while (node) {
    if (node->key == key) return node->val;
    node = node->next;
  }

  return -1;
}

void remove(int key) {
  int hashValue = hashFunction(key);
  Node* node = data[hashValue];

  if (node == NULL) return;
  if (node->key == key) {
    Node* target = node;
    data[hashValue] = node->next;
    delete target;

    return;
  }

  while (node->next) {
    if (node->next->key == key) {
      node->next = node->next->next;
      return;
    }
    node = node->next;
  }
}
```

혹은 STL을 이용한다.

```cpp
unordered_map<int, int> um;

void put(int key, int value) {
  um[key] = value;
}

int get(int key) {
  if (um.count(key) > 0) return um[key];
  return -1;
}

void remove(int key) {
  um.erase(key);
}
```

## 고생한 점
