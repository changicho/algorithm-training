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

// simulation
// time : O(NQ)
// space : O(1)
class Solution {
 public:
  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    const int MOD = 1e9 + 7;
    for (vector<int>& q : queries) {
      for (int i = q[0]; i <= q[1]; i += q[2]) {
        nums[i] = (1LL * nums[i] * q[3]) % MOD;
      }
    }

    int answer = 0;
    for (int& num : nums) {
      answer ^= num;
    }
    return answer;
  }
};