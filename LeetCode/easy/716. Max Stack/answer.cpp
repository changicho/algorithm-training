#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use bruteforce
// time : popMax, peekMax O(N), other O(1)
// space : O(N)
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

// use two stack
// time : read O(1), write O(N)
// space : O(N)
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

// use linked list
// time : write O(log_2(N)), read O(1)
// space : O(N)
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