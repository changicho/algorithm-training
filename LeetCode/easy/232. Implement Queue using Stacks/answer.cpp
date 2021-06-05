#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use two stack push : O(1), pop : O(N)

class MyQueue {
 public:
  stack<int> first;
  stack<int> second;

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
};

// use two stack push : O(N), pop : O(1)

class MyQueue {
 public:
  stack<int> first;
  stack<int> second;

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
};

// use two stack optimized O(1)

class MyQueue {
 public:
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
};