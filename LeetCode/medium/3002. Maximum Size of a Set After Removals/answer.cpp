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
  int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> us1, us2, usAll;
    int n = nums1.size();
    for (int x : nums1) {
      us1.insert(x);
      usAll.insert(x);
    }
    for (int x : nums2) {
      us2.insert(x);
      usAll.insert(x);
    }

    int answer = min(min(n / 2, (int)us1.size()) + min(n / 2, (int)us2.size()),
                     (int)usAll.size());

    return answer;
  }
};