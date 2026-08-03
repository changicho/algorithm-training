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

// brute force
// time : O(N^2 * log_2(M))
// space : O(1)
class Solution {
 public:
  long long maxPairStrength(vector<int>& nums) {
    long long answer = 0;

    int size = nums.size();

    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        long long a = 1LL * nums[i] * nums[j];
        long long b = gcd(nums[i], nums[j]);

        long long cur = a / (b * b);

        answer = max(answer, cur);
      }
    }
    return answer;
  }
};