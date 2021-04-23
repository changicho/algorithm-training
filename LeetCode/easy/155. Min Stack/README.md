# 155. Min Stack

[링크](https://leetcode.com/problems/min-stack/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

연산의 개수는 최대 3 \* 10^4 이다.

스택 안에 숫자가 3 \* 10^4개 까지 들어올 수 있으므로 각 경우마다 최소값을 찾는 법을 최적화 해야한다.

2가지 방법을 사용할 수 있다.

- 스택에 쌓인 숫자마다 그때의 최소값을 같이 저장
- map등을 이용해 O(log_2(N))번 만에 찾기

### 공간 복잡도

두 방법 모두 2개의 자료구조가 필요하다.

해당 자료구조에 필요한 공간 복잡도는 O(N) 이므로 공간 복잡도는 모두 O(N) 이다.

### map, heap을 이용

min 값을 찾는 데 map, heap을 이용해 log_2(N)번 만에 찾을 수 있다.

스택에 값을 push할 때마다 해당 값의 count를 증가시킨다.

pop할 경우에 스택에 더이상 해당 값이 저장되어있지 않은 경우 heap, map에서 해당 값을 지운다.

이 경우 map.begin() key값, heap의 top값은 min값이 된다.

```cpp
class MinStack {
 public:
  /** initialize your data structure here. */
  stack<int> s;
  priority_queue<int, vector<int>, greater<int>> pq;
  map<int, int> m;

  MinStack() {
  }

  void push(int val) {
    pq.push(val);
    s.push(val);
    m[val] += 1;
  }

  void pop() {
    int target = s.top();
    s.pop();

    m[target] -= 1;
    if (m[target] == 0) {
      while (!pq.empty() && m[pq.top()] == 0) {
        pq.pop();
      }
    }
  }

  int top() {
    return s.top();
  }

  int getMin() {
    return pq.top();
  }
};
```

map만 이용

```cpp
class MinStack {
 public:
  /** initialize your data structure here. */
  stack<int> s;
  map<int, int> m;

  MinStack() {
  }

  void push(int val) {
    s.push(val);
    m[val] += 1;
  }

  void pop() {
    int target = s.top();
    s.pop();

    m[target] -= 1;
    if (m[target] == 0) {
      m.erase(target);
    }
  }

  int top() {
    return s.top();
  }

  int getMin() {
    return m.begin()->first;
  }
};
```

### 두개의 stack 이용

스택에 값을 저장할 때 해당 경우에 최소값을 같이 저장한다.

최소값 스택의 경우 top은 항상 해당 경우까지의 가장 작은 값이 저장되어있다.

만약 현재 값이 top보다 작은 경우 최소값 스택에 현재 값을 저장하고 아닌 경우 최소값 스택의 top을 저장한다.

pop연산의 경우 두 스택 모두 pop을 수행한다.

```cpp
class MinStack {
 public:
  stack<int> s;
  stack<int> min_s;

  /** initialize your data structure here. */
  MinStack() {
  }

  void push(int val) {
    s.push(val);
    if (!min_s.empty() && min_s.top() < val) {
      min_s.push(min_s.top());
    } else {
      min_s.push(val);
    }
  }

  void pop() {
    s.pop();
    min_s.pop();
  }

  int top() {
    return s.top();
  }

  int getMin() {
    return min_s.top();
  }
};
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      20      |

## 고생한 점
