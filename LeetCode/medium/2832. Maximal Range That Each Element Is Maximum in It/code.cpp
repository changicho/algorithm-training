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

// use monotonic stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> maximumLengthOfRanges(vector<int>& nums) {
    int size = nums.size();
    vector<int> left(size), right(size);

    stack<int> l2rDesc;
    for (int i = 0; i < size; i++) {
      while (!l2rDesc.empty() && nums[l2rDesc.top()] < nums[i]) {
        l2rDesc.pop();
      }
      left[i] = l2rDesc.empty() ? -1 : l2rDesc.top();
      l2rDesc.push(i);
    }

    stack<int> r2lDesc;
    for (int i = size - 1; i >= 0; i--) {
      while (!r2lDesc.empty() && nums[r2lDesc.top()] < nums[i]) {
        r2lDesc.pop();
      }
      right[i] = r2lDesc.empty() ? size : r2lDesc.top();
      r2lDesc.push(i);
    }

    vector<int> answer(size);
    for (int i = 0; i < size; i++) {
      answer[i] = right[i] - left[i] - 1;
    }

    return answer;
  }
};