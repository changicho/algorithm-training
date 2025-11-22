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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int answer = 0;
    for (int& num : nums) {
      int mod = num % 3;
      answer += min(mod, 3 - mod);
    }
    return answer;
  }
};