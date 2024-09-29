#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use array & two pointer
// time : O(1)
// space : O(K)
class MyCircularDeque {
 private:
  vector<int> arr;
  int left = 0, right = 0, size = 0, capacity;

 public:
  MyCircularDeque(int k) {
    arr = vector<int>(k);
    capacity = k;
  }

  bool insertFront(int value) {
    if (isFull()) return false;

    left = (left - 1 + capacity) % capacity;
    arr[left] = value;

    size++;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) return false;

    arr[right] = value;
    right = (right + 1) % capacity;

    size++;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) return false;

    left = (left + 1) % capacity;

    size--;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) return false;

    right = (right - 1 + capacity) % capacity;

    size--;
    return true;
  }

  int getFront() {
    if (isEmpty()) return -1;

    return arr[left];
  }

  int getRear() {
    if (isEmpty()) return -1;

    return arr[(right - 1 + capacity) % capacity];
  }

  bool isEmpty() { return (size == 0); }

  bool isFull() { return (size == capacity); }
};

// use deque
// time : O(1)
// space : O(K)
class MyCircularDeque {
 private:
  int capacity;
  deque<int> dq;

 public:
  MyCircularDeque(int k) { capacity = k; }

  bool insertFront(int value) {
    if (dq.size() == capacity) return false;
    dq.push_front(value);
    return true;
  }

  bool insertLast(int value) {
    if (dq.size() == capacity) return false;
    dq.push_back(value);
    return true;
  }

  bool deleteFront() {
    if (dq.empty()) return false;
    dq.pop_front();
    return true;
  }

  bool deleteLast() {
    if (dq.empty()) return false;
    dq.pop_back();
    return true;
  }

  int getFront() {
    if (dq.empty()) return -1;
    return dq.front();
  }

  int getRear() {
    if (dq.empty()) return -1;
    return dq.back();
  }

  bool isEmpty() { return dq.empty(); }

  bool isFull() { return dq.size() == capacity; }
};