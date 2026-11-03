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

// max diff
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int maximum = *max_element(nums.begin(), nums.end());

    int answer = 0;

    for (int& num : nums) {
      answer += maximum - num;
    }
    return answer;
  }
};

// max diff with sum
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int size = nums.size();
    int maximum = 0;
    int sum = 0;
    for (int& num : nums) {
      sum += num;
      maximum = max(maximum, num);
    }

    int answer = size * maximum - sum;

    return answer;
  }
};