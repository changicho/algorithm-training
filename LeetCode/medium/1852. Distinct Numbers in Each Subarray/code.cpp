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
// space : O(N)
class Solution {
 public:
  vector<int> distinctNumbers(vector<int>& nums, int k) {
    unordered_map<int, int> counts;

    int size = nums.size();

    vector<int> answer;
    for (int i = 0; i < k; i++) {
      counts[nums[i]]++;
    }
    answer.push_back(counts.size());

    for (int i = k; i < size; i++) {
      counts[nums[i]]++;
      counts[nums[i - k]]--;
      if (counts[nums[i - k]] == 0) counts.erase(nums[i - k]);

      answer.push_back(counts.size());
    }

    return answer;
  }
};