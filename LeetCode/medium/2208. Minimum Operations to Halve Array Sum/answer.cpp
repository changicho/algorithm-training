#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use heap
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int halveArray(vector<int>& nums) {
    // O(N)
    priority_queue<double> maxHeap;
    double sum = 0;

    // O(N)
    for (int& n : nums) {
      sum += n;
      // O(log_2(N))
      maxHeap.push(n);
    }

    double curSum = sum;
    int answer = 0;
    // maximum O(N)
    while (curSum > sum / 2) {
      answer++;

      // O(log_2(N))
      double maximum = maxHeap.top();
      maxHeap.pop();
      curSum -= maximum / 2;
      maxHeap.push(maximum / 2);
    }

    return answer;
  }
};