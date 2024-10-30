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

// use LIS
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  vector<int> getLIS(vector<int>& nums) {
    int size = nums.size();
    vector<int> lengths(size, 1);

    for (int target = 0; target < size; target++) {
      for (int before = 0; before < target; before++) {
        if (nums[before] < nums[target]) {
          lengths[target] = max(lengths[target], lengths[before] + 1);
        }
      }
    }

    return lengths;
  }

 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int size = nums.size();

    vector<int> inc = getLIS(nums);
    reverse(nums.begin(), nums.end());
    vector<int> desc = getLIS(nums);

    reverse(desc.begin(), desc.end());

    int answer = size;
    for (int i = 1; i < size - 1; i++) {
      if (inc[i] > 1 && desc[i] > 1) {
        int cur = inc[i] + desc[i];

        answer = min(answer, size - cur + 1);
      }
    }
    return answer;
  }
};

// use LIS (binary search)
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  vector<int> getLIS(vector<int>& nums) {
    int size = nums.size();
    vector<int> lis;
    vector<int> lengths(size, 1);

    for (int i = 0; i < size; i++) {
      int target = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();

      if (target == lis.size()) {
        lis.push_back(nums[i]);
      } else {
        lis[target] = nums[i];
      }
      lengths[i] = lis.size();
    }

    return lengths;
  }

 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int size = nums.size();

    vector<int> inc = getLIS(nums);
    reverse(nums.begin(), nums.end());
    vector<int> desc = getLIS(nums);

    reverse(desc.begin(), desc.end());

    int answer = size;
    for (int i = 1; i < size - 1; i++) {
      if (inc[i] > 1 && desc[i] > 1) {
        int cur = inc[i] + desc[i];

        answer = min(answer, size - cur + 1);
      }
    }
    return answer;
  }
};