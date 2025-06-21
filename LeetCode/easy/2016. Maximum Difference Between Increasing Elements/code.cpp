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
  int maximumDifference(vector<int>& nums) {
    int size = nums.size();
    int answer = -1;

    int minimum = INT_MAX;
    for (int& num : nums) {
      if (minimum < num) {
        answer = max(answer, num - minimum);
      }
      minimum = min(minimum, num);
    }
    return answer;
  }
};