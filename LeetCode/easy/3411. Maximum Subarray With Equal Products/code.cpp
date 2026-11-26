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
  int maxLength(vector<int>& nums) {
    int size = nums.size();
    int answer = 0;
    for (int i = 0; i < size; i++) {
      long long p = nums[i];
      long long g = nums[i];
      long long l = nums[i];

      for (int j = i + 1; j < size; j++) {
        p = p * nums[j];
        g = gcd(g, nums[j]);
        l = lcm(l, nums[j]);

        if (p > g * l) break;
        if (p == g * l) {
          answer = max(answer, j - i + 1);
        }
      }
    }

    return answer;
  }
};
