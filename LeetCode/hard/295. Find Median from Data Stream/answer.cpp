#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use two priority queue

class MedianFinder {
 private:
  priority_queue<int> lower;
  priority_queue<int, vector<int>, greater<int>> higher;

 public:
  void addNum(int num) {
    higher.push(num);
    if (!lower.empty() && higher.top() < lower.top()) {
      int num1 = higher.top(), num2 = lower.top();

      higher.pop();
      lower.pop();

      higher.push(num2);
      lower.push(num1);
    }

    if (higher.size() > lower.size()) {
      lower.push(higher.top());
      higher.pop();
    }
  }

  double findMedian() {
    if (lower.size() > higher.size()) return lower.top();

    int left = lower.top();
    int right = higher.top();

    return (double)(left + right) / 2;
  }
};

// use insert sort (TL)

class MedianFinder {
  vector<int> nums;

 public:
  void addNum(int num) {
    if (nums.empty()) {
      nums.push_back(num);
    } else {
      auto iter = lower_bound(nums.begin(), nums.end(), num);
      nums.insert(iter, num);
    }
  }

  double findMedian() {
    int size = nums.size();

    if (size % 2 == 1) return nums[size / 2];
    return (double)(nums[size / 2 - 1] + nums[size / 2]) / 2;
  }
};