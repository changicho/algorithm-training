# 641. Design Circular Deque

[링크](https://leetcode.com/problems/design-circular-deque/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 데크의 크기를 K라 하자.

배열과 투 포인터를 이용해 구현할 경우 모든 연산의 시간 복잡도는 O(1)이다.

데크를 사용할 경우 O(1)의 시간 복잡도로 모든 연산을 수행할 수 있다.

### 공간 복잡도

각 값들을 저장하는데 O(K)의 공간 복잡도가 필요하다.

### 배열 & 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      22      |    O(1)     |    O(K)     |

배열과 현재 데크의 맨 앞, 맨 뒤를 가리키는 투 포인터를 사용한다.

```cpp
vector<int> arr;
int left = 0, right = 0, size = 0, capacity;

MyCircularDeque(int k) {
  arr = vector<int>(k);
  capacity = k;
}

bool insertFront(int value) {
  if (isFull()) return false;

  left = (left - 1 + capacity) % capacity;
  arr[left] = value;

  size++;
  return true;
}

bool insertLast(int value) {
  if (isFull()) return false;

  arr[right] = value;
  right = (right + 1) % capacity;

  size++;
  return true;
}

bool deleteFront() {
  if (isEmpty()) return false;

  left = (left + 1) % capacity;

  size--;
  return true;
}

bool deleteLast() {
  if (isEmpty()) return false;

  right = (right - 1 + capacity) % capacity;

  size--;
  return true;
}

int getFront() {
  if (isEmpty()) return -1;

  return arr[left];
}

int getRear() {
  if (isEmpty()) return -1;

  return arr[(right - 1 + capacity) % capacity];
}

bool isEmpty() { return (size == 0); }

bool isFull() { return (size == capacity); }
```

### 데크

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(1)     |    O(K)     |

```cpp
int capacity;
deque<int> dq;

MyCircularDeque(int k) { capacity = k; }

bool insertFront(int value) {
  if (dq.size() == capacity) return false;
  dq.push_front(value);
  return true;
}

bool insertLast(int value) {
  if (dq.size() == capacity) return false;
  dq.push_back(value);
  return true;
}

bool deleteFront() {
  if (dq.empty()) return false;
  dq.pop_front();
  return true;
}

bool deleteLast() {
  if (dq.empty()) return false;
  dq.pop_back();
  return true;
}

int getFront() {
  if (dq.empty()) return -1;
  return dq.front();
}

int getRear() {
  if (dq.empty()) return -1;
  return dq.back();
}

bool isEmpty() { return dq.empty(); }

bool isFull() { return dq.size() == capacity; }
```

## 고생한 점
