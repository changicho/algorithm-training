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

// use greedy
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long findMaximumScore(vector<int>& nums) {
    long long answer = 0;

    int maximum = 0;
    for (int& num : nums) {
      answer += maximum;
      maximum = max(num, maximum);
    }
    return answer;
  }
};