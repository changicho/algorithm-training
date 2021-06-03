# 225. Implement Stack using Queues

[링크](https://leetcode.com/problems/implement-stack-using-queues/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

FIFO 구조인 queue를 이용해 stack을 만들 경우 특정 연산을 수행할 때 맨 처음 들어온 요소를 찾아야 한다.

따라서 하나의 연산에서 O(N)의 시간 복잡도가 소요되므로 최종적으로 시간 복잡도는 O(N)이다.

### 공간 복잡도

2개의 큐를 이용할수도, 1개의 큐를 이용해 구현할 수 도 있다.

이 경우 공간 복잡도는 O(N)이다.

### use two queue, push : O(1), pop : O(N)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

2개의 큐를 이용한다.

push 연산에는 그냥 일반 큐에 숫자를 쌓는다.

pop과 top 연산에서 제일 끝 요소를 찾기 위해 기존 요소를 pop하며 임시 큐에 저장한다.

이후 그 요소를 반환하기 위해 따로 저장한뒤, top의 경우 임시 큐에 넣는다.

이후 임시 큐의 내용물을 그래도 일반 큐에 옮긴다.

```cpp
queue<int> first;
queue<int> second;

void push(int x) {
  first.push(x);
}

int pop() {
  if (first.empty()) return -1;

  while (first.size() > 1) {
    second.push(first.front());
    first.pop();
  }

  int target = first.front();
  first.pop();

  while (!second.empty()) {
    first.push(second.front());
    second.pop();
  }

  return target;
}

int top() {
  if (first.empty()) return -1;

  while (first.size() > 1) {
    second.push(first.front());
    first.pop();
  }

  int target = first.front();
  second.push(first.front());
  first.pop();

  while (!second.empty()) {
    first.push(second.front());
    second.pop();
  }

  return target;
}

bool empty() {
  return first.empty();
}
```

### use one queue, push : O(1), pop : O(N)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

위 방법에서 임시 큐로 옮기지 않고 현재 큐의 사이즈 - 1번 만큼만 shift 연산을 수행한다.

이후 top, pop에 따라서 시프트를 한번 더 할지, 제거만 할지를 정한다.

```cpp
queue<int> q;

void push(int x) {
  q.push(x);
}

int pop() {
  if (q.empty()) return -1;
  int size = q.size();

  for (int i = 0; i < size - 1; i++) {
    q.push(q.front());
    q.pop();
  }

  int target = q.front();
  q.pop();

  return target;
}

int top() {
  if (q.empty()) return -1;
  int size = q.size();

  for (int i = 0; i < size - 1; i++) {
    q.push(q.front());
    q.pop();
  }

  int target = q.front();
  q.pop();
  q.push(target);

  return target;
}

bool empty() {
  return q.empty();
}
```

### use one queue, push : O(N), pop : O(1)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

위 방법은 pop, top에서 O(N)의 시간 복잡도인 방법이다.

push 연산을 수행할 때 애초에 LIFO 순으로 정렬할 경우 pop, top의 경우 O(1)의 방법으로 구현 가능하다.

매번 새로운 수를 push 할 때마다 기존 queue의 내용을 shift 한다.

```cpp
queue<int> q;

void push(int x) {
  q.push(x);

  // sort reverse
  int size = q.size();
  for (int i = 1; i < size; i++) {
    q.push(q.front());
    q.pop();
  }
}

int pop() {
  int target = q.front();
  q.pop();
  return target;
}

int top() {
  return q.front();
}

bool empty() {
  return q.empty();
}
```

## 고생한 점
