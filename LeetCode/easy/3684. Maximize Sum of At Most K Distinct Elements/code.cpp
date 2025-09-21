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

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> maxKDistinct(vector<int>& nums, int k) {
    int size = nums.size();
    sort(nums.begin(), nums.end(), greater<int>());

    vector<int> answer;

    for (int i = 0; i < size; i++) {
      if (answer.empty() || answer.back() != nums[i]) {
        answer.push_back(nums[i]);
      }
      if (answer.size() == k) break;
    }
    return answer;
  }
};