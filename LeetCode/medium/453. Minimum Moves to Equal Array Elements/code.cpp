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

// math
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int answer = 0;
    int minimum = *min_element(nums.begin(), nums.end());

    for (int& num : nums) {
      answer += num - minimum;
    }
    return answer;
  }
};