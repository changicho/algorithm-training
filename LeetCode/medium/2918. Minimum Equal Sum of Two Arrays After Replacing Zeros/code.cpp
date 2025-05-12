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

// use one pass
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    int zeroCount1 = 0, zeroCount2 = 0;
    long long sum1 = 0, sum2 = 0;

    for (int& num : nums1) {
      if (num == 0) {
        zeroCount1++;
      }
      sum1 += num;
    }
    for (int& num : nums2) {
      if (num == 0) {
        zeroCount2++;
      }
      sum2 += num;
    }

    if (zeroCount1 < zeroCount2) {
      swap(zeroCount1, zeroCount2);
      swap(sum1, sum2);
    }

    if (zeroCount2 == 0) {
      if (zeroCount1 == 0 && sum1 != sum2) return -1;
      if (sum1 + zeroCount1 > sum2) return -1;

      return sum2;
    }

    return max(sum1 + zeroCount1, sum2 + zeroCount2);
  }
};

// use one pass
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    int zeroCount1 = 0, zeroCount2 = 0;
    long long sum1 = 0, sum2 = 0;

    for (int& num : nums1) {
      if (num == 0) {
        zeroCount1++;
      }
      sum1 += num;
    }
    for (int& num : nums2) {
      if (num == 0) {
        zeroCount2++;
      }
      sum2 += num;
    }

    if (zeroCount2 == 0 && sum1 + zeroCount1 > sum2 + zeroCount2) {
      return -1;
    }
    if (zeroCount1 == 0 && sum1 + zeroCount1 < sum2 + zeroCount2) {
      return -1;
    }

    return max(sum1 + zeroCount1, sum2 + zeroCount2);
  }
};