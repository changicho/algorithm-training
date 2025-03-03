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

// use two pointer
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                  vector<vector<int>>& nums2) {
    vector<vector<int>> answer;

    int size1 = nums1.size(), size2 = nums2.size();
    int i1 = 0, i2 = 0;

    while (i1 < size1 && i2 < size2) {
      vector<int> cur = {0, 0};
      if (nums1[i1][0] < nums2[i2][0]) {
        cur = nums1[i1];
        i1++;
      } else if (nums1[i1][0] > nums2[i2][0]) {
        cur = nums2[i2];
        i2++;
      } else {
        cur = nums1[i1];
        cur[1] += nums2[i2][1];
        i1++;
        i2++;
      }

      answer.push_back(cur);
    }

    while (i1 < size1) {
      answer.push_back(nums1[i1]);
      i1++;
    }
    while (i2 < size2) {
      answer.push_back(nums2[i2]);
      i2++;
    }
    return answer;
  }
};