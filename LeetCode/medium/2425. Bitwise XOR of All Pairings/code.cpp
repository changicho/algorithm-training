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

// use commutative property
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size(), size2 = nums2.size();

    int answer = 0;
    for (int& num : nums1) {
      if (size2 % 2 == 1) answer ^= num;
    }
    for (int& num : nums2) {
      if (size1 % 2 == 1) answer ^= num;
    }
    return answer;
  }
};