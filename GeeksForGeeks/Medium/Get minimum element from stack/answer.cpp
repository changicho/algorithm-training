#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

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
