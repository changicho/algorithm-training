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

// use one pass & mod
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> answer;

    long long cur = 0;
    for (int& num : nums) {
      cur += num;

      answer.push_back(cur % 5 == 0);

      cur *= 2;
      cur %= 5;
    }
    return answer;
  }
};