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

// use sort
// time : O(N * log_2(N) + M * log_2(M))
// space : O(N + M)
class Solution {
 private:
  int calc(vector<int>& nums) {
    int ret = 1;

    sort(nums.begin(), nums.end());
    int before = -100;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == before + 1) {
        count++;
        before = nums[i];
      } else {
        count = 1;
        before = nums[i];
      }

      ret = max(ret, count + 1);
    }
    return ret;
  }

 public:
  int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                             vector<int>& vBars) {
    int hMax = calc(hBars);
    int vMax = calc(vBars);

    int length = min(hMax, vMax);

    return length * length;
  }
};