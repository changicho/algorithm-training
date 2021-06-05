# 232. Implement Queue using Stacks

[링크](https://leetcode.com/problems/implement-queue-using-stacks/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

스택을 이용해 큐를 구현할 경우 LIFO구조를 FIFO구조로 변경해야 햐므로 push 또는 pop 연산에 순서를 바꿔주기 위해 O(N)의 시간복잡도가 필요하다.

최악의 경우 O(N)이므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

요소를 모두 저장해야 하므로 O(N)의 공간 복잡도가 필요하다.

### 2개의 스택 O(N)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

기존 LIFO구조로 자료를 저장하고 FIFO로 변환하기 위해 O(N)의 시간 복잡도가 소요된다.

이 때 저장시에 변환하는 경우와, 뽑을때 변환하는 경우 두가지 방법이 존재한다.

뽑을 때 변환하는 경우는 다음과 같다.

```cpp
// use two stack push : O(1), pop : O(N)
stack<int> first, second;

void push(int x) {
  first.push(x);
}

int pop() {
  while (first.size() > 1) {
    second.push(first.top());
    first.pop();
  }
  int target = first.top();
  first.pop();

  while (!second.empty()) {
    first.push(second.top());
    second.pop();
  }
  return target;
}

int peek() {
  while (first.size() > 1) {
    second.push(first.top());
    first.pop();
  }
  int target = first.top();

  while (!second.empty()) {
    first.push(second.top());
    second.pop();
  }
  return target;
}

bool empty() {
  return first.empty();
}
```

저장시의 변환하는 경우는 다음과 같다.

```cpp
// use two stack push : O(N), pop : O(1)
stack<int> first, second;

void push(int x) {
  while (!first.empty()) {
    second.push(first.top());
    first.pop();
  }
  first.push(x);
  while (!second.empty()) {
    first.push(second.top());
    second.pop();
  }
}

int pop() {
  int target = first.top();
  first.pop();

  return target;
}

int peek() {
  return first.top();
}

bool empty() {
  return first.empty();
}
```

### 2개의 스택 최적화된 방법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(1), O(N)  |    O(N)     |

처음 스택에 자료를 쌓을 때는 LIFO구조이다.

이 스택을 두번째 스택에 순서대로 다시 쌓을 경우 (LIFO > LIFO) 이므로 FIFO구조가 된다.

따라서 pop 혹은 peek연산 시에 두번째 스택을 갱신하며 top의 값을 뽑아낼 경우 FIFO구조가 된다.

만약 두번째 스택이 비어져있는 경우 첫번째 스택의 모든 값을 두번째 스택에 옮긴다.

이 방법을 이용하면 두번째 스택이 매번 비어있지 않는 한 push와 pop에 O(1)의 시간복잡도가 필요하다.

```cpp
stack<int> first, second;

void push(int x) {
  first.push(x);
}

int pop() {
  int target = peek();
  second.pop();
  return target;
}

int peek() {
  if (second.empty()) {
    while (!first.empty()) {
      second.push(first.top());
      first.pop();
    }
  }
  return second.top();
}

bool empty() {
  return first.empty() && second.empty();
}
```

## 고생한 점
