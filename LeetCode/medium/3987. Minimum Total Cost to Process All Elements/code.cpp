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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumCost(vector<int>& nums, int k) {
    const int MOD = 1e9 + 7;

    int cost = 0;
    long long r = k;
    for (int& num : nums) {
      if (r >= num) {
        r -= num;
      } else {
        int diff = num - r;
        int count = (diff + k - 1) / k;

        r += (long long)k * count;
        r -= num;
        cost += count;
        cost %= MOD;
      }
    }

    int answer = ((long long)(cost) * (cost + 1) / 2) % MOD;
    return answer;
  }
};