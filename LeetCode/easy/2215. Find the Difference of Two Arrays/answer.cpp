#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> ans(2);
    unordered_set<int> us1(nums1.begin(), nums1.end()),
        us2(nums2.begin(), nums2.end());

    for (int n : us1) {
      if (us2.count(n) == 0) {
        ans[0].push_back(n);
      }
    }

    for (int n : us2) {
      if (us1.count(n) == 0) {
        ans[1].push_back(n);
      }
    }
    return ans;
  }
};