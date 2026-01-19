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

// use hash set
// time : O(N^2 + M^2)
// space : O(N^2 + M^2)
class Solution {
 private:
  unordered_set<int> check(int limit, vector<int>& nums) {
    int start = 1;
    unordered_set<int> ret;
    ret.insert(limit - start);

    int size = nums.size();
    for (int i = 0; i < size; i++) {
      int num = nums[i];
      ret.insert(num - 1);
      ret.insert(limit - num);

      for (int j = i + 1; j < size; j++) {
        ret.insert(abs(nums[j] - nums[i]));
      }
    }
    return ret;
  }

 public:
  int maximizeSquareArea(int m, int n, vector<int>& hFences,
                         vector<int>& vFences) {
    const int MOD = 1e9 + 7;

    unordered_set<int> hSet = check(m, hFences), vSet = check(n, vFences);

    int answer = -1;
    for (int num : hSet) {
      if (vSet.count(num) > 0) {
        answer = max(answer, num);
      }
    }
    if (answer == -1) return -1;
    return (long long)answer * answer % MOD;
  }
};