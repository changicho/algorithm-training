#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> us1(nums1.begin(), nums1.end()),
        us2(nums2.begin(), nums2.end());

    int count1 = 0, count2 = 0;

    for (int& num : nums1) {
      if (us2.count(num)) count1++;
    }
    for (int& num : nums2) {
      if (us1.count(num)) count2++;
    }

    return {count1, count2};
  }
};