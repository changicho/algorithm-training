# Get minimum element from stack

[링크](https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

O(1)번 이내에 연산을 수행 해야 한다.

### 공간 복잡도

O(1)의 공간복잡도로 문제를 해결해야 한다. 따라서 min값들을 저장하는 stack을 사용할 수 없다.

minEle요소와 stack에 쌓는 값을 서로 이용해 해당 상태에서 최소값과 실제 값을 구해야 한다.

### 숫자 변환

| 내 코드 (s) | 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: | :---------: |
|    0.01     |    O(1)     |    O(1)     |

값을 push할 때마다 minEle와 비교해 새로운 최소값인지를 판단한다.

만약 새로운 최소 값인 경우 값을 그대로 저장하는 것이 아니라 바뀌기 전 최소값을 이용해 연산한 값을 저장한다.

이는 주어진 숫자가 1 ~ 100 까지만 주어지기 때문에 사용할 수 있는 방법이다.

만약 음수가 주어지는 경우에는 치환시에 대소비교가 반대로 되기 때문에 사용할 수 없다.

pop 연산에서 현재 빼려는 값이 최소값인 경우 현재 상태의 값의 의미는 다음과 같다.

- x는 실제 값이며 minEle = x이다.
- topValue = x - beforeMin로 저장되었다.
- minEle = minEle - topValue 식은 결국 x - x + beforeMin으로 식이 치환되어 beforeMin을 구할 수 있다.

push 연산에서 새로운 min값을 집어 넣는 경우 다음과 같다.

- 이전 minEle 상태를 저장하며 x를 새로운 minEle로 저장해야 한다.
- 따라서 x - minEle는 x보다 작음이 보장되므로 이를 이용해 나중에 pop을 할 때 최소값을 빼는 상황인지 알 수 있다.
- 이후 pop하는 상황에서 minEle를 이용해 beforeMin을 구할 수 있다.

```cpp
class _stack {
  stack<int> s;
  int minEle;

 public:
  int getMin();
  int pop();
  void push(int);
};

int _stack ::getMin() {
  if (s.empty()) return -1;
  return minEle;
}

int _stack ::pop() {
  if (s.empty()) return -1;

  int topValue = s.top();
  s.pop();

  if (topValue < minEle) {  // 현재 빼려는 값이 최소값인 경우
    int x = minEle;
    // 현재 상태의 값의 의미는 다음과 같다.
    // x는 실제 값이며 minEle = x이다.
    // topValue = x - beforeMin로 저장되었었기 때문에
    // x - x + beforeMin으로 식이 치환되어 beforeMin을 구할 수 있다.
    minEle = minEle - topValue;
    return x;
  } else {
    return topValue;
  }
}

void _stack::push(int x) {
  if (s.empty()) {
    minEle = x;
    s.push(x);

    return;
  }

  if (x < minEle) {
    // 이전 minEle 상태를 저장하며 x를 새로운 minEle로 저장해야 한다.
    // 따라서 x - minEle는 x보다 작음이 보장되므로 이를 이용해 나중에 pop을 할 때 최소값을 빼는 상황인지 알 수 있다.
    // 이후 pop하는 상황에서 minEle를 이용해 beforeMin을 구할 수 있다.
    s.push(x - minEle);
    minEle = x;
  } else {
    s.push(x);
  }
}
```

## 고생한 점

minStack을 별도로 사용한 경우 testCase마다 초기화를 해야한다.
