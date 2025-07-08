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

// use hash map
// time : O(N + M)
// space : O(N + M)
class FindSumPairs {
 private:
  vector<int> nums1, nums2;
  unordered_map<int, int> um;

 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    for (int& num : nums2) {
      um[num]++;
    }
  }

  void add(int index, int val) {
    int before = nums2[index];

    um[before]--;
    nums2[index] += val;
    um[before + val]++;
  }

  int count(int tot) {
    int ret = 0;
    for (int& num : nums1) {
      int rest = tot - num;

      if (um.count(rest)) {
        ret += um[rest];
      }
    }
    return ret;
  }
};