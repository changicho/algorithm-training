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

// use array
// time : O(1), O(N)
// space : O(N)
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

// use lazy propagation
// time : O(1), O(1)
// space : O(N)
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
