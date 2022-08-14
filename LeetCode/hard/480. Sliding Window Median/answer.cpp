#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use multiset
// time : O(N * log_2(K))
// space : O(N)
class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    int size = nums.size();

    vector<double> medians;
    multiset<int> lower, higher;

    for (int i = 0; i < size; i++) {
      if (i >= k) {
        if (nums[i - k] <= *lower.rbegin()) {
          lower.erase(lower.find(nums[i - k]));
        } else {
          higher.erase(higher.find(nums[i - k]));
        }
      }

      lower.insert(nums[i]);

      higher.insert(*lower.rbegin());
      lower.erase(prev(lower.end()));

      if (lower.size() < higher.size()) {
        lower.insert(*higher.begin());
        higher.erase(higher.begin());
      }

      if (i >= k - 1) {
        double median;
        if (k % 2 == 1) {
          median = *lower.rbegin();
        } else {
          median = ((double)(*lower.rbegin()) + (*higher.begin())) / 2;
        }
        medians.push_back(median);
      }
    }

    return medians;
  }
};