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

// use group & sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
    int size = nums.size();

    // make group by limit
    vector<int> copied = nums;
    sort(copied.begin(), copied.end());

    vector<deque<int>> groups;
    groups.push_back({});
    for (int &num : copied) {
      if (!groups.back().empty() && num - groups.back().back() > limit) {
        groups.push_back({});
      }

      groups.back().push_back(num);
    }

    unordered_map<int, int> um;
    for (int g = 0; g < groups.size(); g++) {
      for (int &num : groups[g]) {
        um[num] = g;
      }
    }

    // change group num to sorted
    for (int i = 0; i < size; i++) {
      int g = um[nums[i]];

      nums[i] = groups[g].front();
      groups[g].pop_front();
    }

    return nums;
  }
};