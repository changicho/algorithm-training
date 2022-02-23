# 716. Max Stack

[링크](https://leetcode.com/problems/max-stack/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

원소의 갯수를 N이라 하자.

배열을 이용해 모든 연산을 직접 구현할 경우 시간 복잡도는 다음과 같다.

- 일반 stack연산 : O(1)
- max연산 : O(N)

두개의 스택을 이용해 peekMax를 최적화 할 수 있다. 이 경우 시간 복잡도는 다음과 같다.

- push, pop, top, peekMax : O(1)
- popMax : O(N)

### 공간 복잡도

원소들을 저장할 공간이 필요하므로 O(N)의 공간 복잡도를 사용한다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      72      |    O(N)     |    O(N)     |

vector에 값들을 저장한 뒤 max에 관련된 연산이 있을 때마다 모든 원소를 순회해 찾거나 삭제한다.

```cpp
class MaxStack {
 private:
  vector<int> array;

 public:
  void push(int x) { array.push_back(x); }

  int pop() {
    int target = array.back();
    array.pop_back();

    return target;
  }

  int top() {
    int target = array.back();

    return target;
  }

  int peekMax() {
    int maximum = array.front();
    for (int &num : array) {
      maximum = max(maximum, num);
    }
    return maximum;
  }

  int popMax() {
    int maxIdx = 0;
    for (int i = 0; i < array.size(); i++) {
      if (array[i] >= array[maxIdx]) {
        maxIdx = i;
      }
    }

    int target = array[maxIdx];
    array.erase(array.begin() + maxIdx);

    return target;
  }
};
```

### 2 stack

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     116      |    O(N)     |    O(N)     |

값을 저장하는 스택과 maxStack 두 가지를 사용한다.

값을 저장할 때 maxStack.top값보다 작은 경우는 maxStack에 저장하지 않는다.

이를 이용해 peekMax 연산을 O(1)의 시간 복잡도로 구현 가능하다.

popMax의 경우 연산시 maxStack의 top을 없앤다. 이후 해당 원소를 원소를 저장하는 stack에서 제거한다.

```cpp
class MaxStack {
  stack<int> valueStack;
  stack<int> maxStack;

 public:
  void push(int x) {
    valueStack.push(x);
    if (maxStack.empty() || maxStack.top() <= x) maxStack.push(x);
  }

  int pop() {
    int target = valueStack.top();
    valueStack.pop();
    if (target == peekMax()) maxStack.pop();
    return target;
  }

  int top() { return valueStack.top(); }

  int peekMax() { return maxStack.top(); }

  int popMax() {
    int maximum = peekMax();
    stack<int> temp;
    while (top() != maximum) {
      temp.push(pop());
    }

    pop();

    while (!temp.empty()) {
      push(temp.top());
      temp.pop();
    }

    return maximum;
  }
};
```

### BST map & linked list

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      72      | O(log_2(N)) |    O(N)     |

BST기반의 map과 연결 리스트를 이용해 연산을 최적화 할 수 있다.

각 값을 key로 하고, 링크드 리스트의 노드들을 value로 하는 BST가 존재한다고 하자.

maxElement는 BST가 값에 대해 정렬되어 있으므로 바로 구할 수 있다.

만약 삭제 연산을 수행할 때 BST에서 링크드 리스트의 노드 중 맨 뒤의 노드를 찾아 삭제해 이를 최적화 할 수 있다.

이 과정에서 해당 값이 연결 리스트에 더이상 존재하지 않는 경우 삭제한다.

```cpp
class MaxStack {
 private:
  list<int> values;
  map<int, vector<list<int>::iterator>> valueToIter;

 public:
  void push(int x) {
    // O(1)
    values.insert(values.begin(), x);
    // O(log_2(N))
    valueToIter[x].push_back(values.begin());
  }

  int pop() {
    // O(1)
    int target = *values.begin();
    // O(log_2(N))
    valueToIter[target].pop_back();

    if (valueToIter[target].empty()) valueToIter.erase(target);
    values.erase(values.begin());

    return target;
  }

  int top() {
    // O(1)
    return *values.begin();
  }

  int peekMax() {
    // O(1)
    return valueToIter.rbegin()->first;
  }

  int popMax() {
    int target = valueToIter.rbegin()->first;
    // O(log_2(N))
    auto it = valueToIter[target].back();
    // O(log_2(N))
    valueToIter[target].pop_back();

    if (valueToIter[target].empty()) valueToIter.erase(target);
    values.erase(it);

    return target;
  }
};
```

## 고생한 점
