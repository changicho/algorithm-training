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

// use mod count
// time : O(N)
// space : O(1)
class Solution {
 private:
  void insert(pair<long long, long long>& p, int num) {
    if (p.first >= num) {
      p.second = p.first;
      p.first = num;
    } else if (p.second > num) {
      p.second = num;
    }
  }

 public:
  int maxSumDivThree(vector<int>& nums) {
    int size = nums.size();

    int sum = 0;
    vector<pair<long long, long long>> mods(3, {INT_MAX, INT_MAX});
    for (int& num : nums) {
      sum += num;
      int key = num % 3;

      if (key == 0) continue;
      insert(mods[key], num);
    }

    int mod = sum % 3;
    long long oneDiff = INT_MAX;
    long long twoDiff = INT_MAX;
    if (mod == 0) {
      oneDiff = twoDiff = 0;
    } else if (mod == 1) {
      oneDiff = mods[1].first;
      twoDiff = 0LL + mods[2].first + mods[2].second;
    } else if (mod == 2) {
      oneDiff = mods[1].first + mods[1].second;
      twoDiff = mods[2].first;
    }

    long long diff = min(oneDiff, twoDiff);
    if (diff == INT_MAX) return 0;
    sum -= diff;

    return sum;
  }
};