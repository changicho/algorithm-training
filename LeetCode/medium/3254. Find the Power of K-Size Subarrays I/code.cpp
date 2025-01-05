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

// use sliding window
// time : O(N)
// space : O(K)
class Solution {
 public:
  vector<int> resultsArray(vector<int>& nums, int k) {
    int size = nums.size();
    deque<int> dq;

    vector<int> answer;

    for (int i = 0; i < size; i++) {
      if (dq.size() >= k) {
        dq.pop_front();
      }

      if (!dq.empty() && dq.back() + 1 != nums[i]) {
        dq.clear();
      }
      dq.push_back(nums[i]);

      if (i >= k - 1) {
        if (dq.size() == k) {
          answer.push_back(dq.back());
        } else {
          answer.push_back(-1);
        }
      }
    }
    return answer;
  }
};