#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use heap
// time : O((K + N) * log_2(N))
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int maximumProduct(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int& n : nums) {
      minHeap.push(n);
    }

    while (k--) {
      int cur = minHeap.top();
      minHeap.pop();
      cur++;
      cur %= MOD;

      minHeap.push(cur);
    }

    int product = 1;
    while (!minHeap.empty()) {
      product = ((long)product * minHeap.top()) % MOD;
      minHeap.pop();
    }
    return product;
  }
};