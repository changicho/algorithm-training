#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use heap

class KthLargest {
 private:
  // store biggest k num
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int k;

 public:
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for (int& num : nums) {
      minHeap.push(num);
    }

    while (minHeap.size() > k) {
      minHeap.pop();
    }
  }

  int add(int val) {
    minHeap.push(val);

    while (minHeap.size() > k) {
      minHeap.pop();
    }

    return minHeap.top();
  }
};
