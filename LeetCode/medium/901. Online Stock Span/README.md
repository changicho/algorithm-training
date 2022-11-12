# 901. Online Stock Span

[링크](https://leetcode.com/problems/online-stock-span/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

next 연산의 총 횟수를 N이라 하자.

이 경우 각 next 연산마다, 직전 최근 값들을 연이어 순회했을때 자신보다 작은 값의 갯수를 세야 한다.

이를 모두 직접 찾을 경우 O(N^2)의 시간 복잡도를 사용한다.

stack을 이용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

이전 값들을 저장할 공간에 O(N)의 공간 복잡도를 사용한다.

stack을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     457      |    O(N)     |    O(N)     |

각 값들을 삽입할 때, 현재 값의 index와 현재 값을 stack에 저장한다.

이 때 값을 저장하기 전 스택에 존재하는 자신보다 작은 값들을 모두 pop한다.

이 경우 stack의 top과 현재 index간의 차이가 반환해야 하는 값 (자신보다 작은 값의 갯수)이 된다.

이전에 삽입한 값을 A, 현재 삽입하고자 하는 값을 B라 하자.

- A > B : 이 경우 stack의 top은 A가 되며 1이다.
- A < B : 이미 A보다 작은 값들은 stack에서 사라졌으므로 이후 stack에서 pop연산을 계속한다.

이를 구현하면 다음과 같다.

```cpp
class StockSpanner {
 private:
  struct Price {
    int price, index;
  };

  stack<Price> stk;
  int index = 0;

 public:
  StockSpanner() { stk.push({INT_MAX, -1}); }

  int next(int price) {
    int count = 0;
    while (stk.top().price <= price) {
      stk.pop();
    };
    int ret = index - stk.top().index;
    stk.push({price, index});
    index++;
    return ret;
  }
};
```

## 고생한 점
