#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// greedy & counting
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                             int k2) {
    int size = nums1.size();
    int count[100001] = {
        0,
    };

    int maximum = 0;
    for (int i = 0; i < size; i++) {
      int diff = abs(nums1[i] - nums2[i]);
      maximum = max(maximum, diff);
      count[diff]++;
    }

    long long answer = 0;
    int k = k1 + k2;
    for (int num = maximum; num >= 1; num--) {
      if (count[num] == 0) continue;

      int minus = min(k, count[num]);

      k -= minus;
      count[num] -= minus;
      count[num - 1] += minus;

      answer += (long long)num * num * count[num];
    }

    return answer;
  }
};