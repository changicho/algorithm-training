#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// use heap

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

// use only map

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

// use only stack

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
