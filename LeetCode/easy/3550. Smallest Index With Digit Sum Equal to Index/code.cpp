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
// time : O(N * log_10(M))
// space : O(1)
class Solution {
 public:
  int smallestIndex(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      int sum = 0;
      while (nums[i] > 0) {
        sum += nums[i] % 10;
        nums[i] /= 10;
      }
      if (sum == i) return i;
    }
    return -1;
  }
};