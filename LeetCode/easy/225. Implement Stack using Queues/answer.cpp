#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use two queue, push : O(1), pop : O(N)

class MyStack {
  queue<int> first;
  queue<int> second;

 public:
  void push(int x) {
    first.push(x);
  }

  int pop() {
    if (first.empty()) return -1;

    while (first.size() > 1) {
      second.push(first.front());
      first.pop();
    }

    int target = first.front();
    first.pop();

    while (!second.empty()) {
      first.push(second.front());
      second.pop();
    }

    return target;
  }

  int top() {
    if (first.empty()) return -1;

    while (first.size() > 1) {
      second.push(first.front());
      first.pop();
    }

    int target = first.front();
    second.push(first.front());
    first.pop();

    while (!second.empty()) {
      first.push(second.front());
      second.pop();
    }

    return target;
  }

  bool empty() {
    return first.empty();
  }
};

// use one queue, push : O(1), pop : O(N)

class MyStack {
  queue<int> q;

 public:
  void push(int x) {
    q.push(x);
  }

  int pop() {
    if (q.empty()) return -1;
    int size = q.size();

    for (int i = 0; i < size - 1; i++) {
      q.push(q.front());
      q.pop();
    }

    int target = q.front();
    q.pop();

    return target;
  }

  int top() {
    if (q.empty()) return -1;
    int size = q.size();

    for (int i = 0; i < size - 1; i++) {
      q.push(q.front());
      q.pop();
    }

    int target = q.front();
    q.pop();
    q.push(target);

    return target;
  }

  bool empty() {
    return q.empty();
  }
};

// use one queue, push : O(N), pop : O(1)

class MyStack {
  queue<int> q;

 public:
  void push(int x) {
    q.push(x);

    // sort reverse
    int size = q.size();
    for (int i = 1; i < size; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    int target = q.front();
    q.pop();
    return target;
  }

  int top() {
    return q.front();
  }

  bool empty() {
    return q.empty();
  }
};