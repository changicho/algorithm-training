# 1381. Design a Stack With Increment Operation

[링크](https://leetcode.com/problems/design-a-stack-with-increment-operation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

CustomStack의 최대 크기를 N이라 하자.

배열을 이용해 구현할 경우 push, pop에 O(1)의 시간 복잡도가 소요된다.

이후 increment를 수행할 때, increment를 수행할 index까지만 증가시키면 되므로 O(N)의 시간 복잡도가 소요된다.

lazy propagation을 이용할 경우 increment를 수행할 때 O(1)의 시간 복잡도가 소요된다.

### 공간 복잡도

숫자를 저장하는데 O(N)의 공간 복잡도가 필요하다.

### 배열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(N)     |

```cpp
class CustomStack {
 private:
  vector<int> arr;
  int capacity;

 public:
  CustomStack(int maxSize) { capacity = maxSize; }

  void push(int x) {
    if (arr.size() == capacity) return;
    arr.push_back(x);
  }

  int pop() {
    if (arr.size() == 0) return -1;
    int target = arr.back();
    arr.pop_back();
    return target;
  }

  void increment(int k, int val) {
    int limit = min((int)arr.size(), k);
    for (int i = 0; i < limit; i++) {
      arr[i] += val;
    }
  }
};
```

### lazy propagation

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      25      |    O(N)     |    O(N)     |

현재 까지 increment된 값을 누적할 배열을 추가한다.

이 때 increment된 마지막 index에만 값을 더해준 뒤, pop할 때 영향을 받는 이전값에 현재까지 누적된 값을 더해준다.

```cpp
class CustomStack {
 private:
  vector<int> arr;
  vector<int> lazy;
  int capacity;

 public:
  CustomStack(int maxSize) { capacity = maxSize; }

  void push(int x) {
    if (arr.size() == capacity) return;
    arr.push_back(x);
    lazy.push_back(0);
  }

  int pop() {
    if (arr.size() == 0) return -1;
    int target = arr.back();
    arr.pop_back();

    int sum = lazy.back();
    lazy.pop_back();
    if (lazy.size() > 0) {
      lazy[lazy.size() - 1] += sum;
    }
    return target + sum;
  }

  void increment(int k, int val) {
    int index = min((int)arr.size(), k) - 1;
    if (index < lazy.size()) lazy[index] += val;
  }
};
```

## 고생한 점
