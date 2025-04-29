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
  int countSubarrays(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;
    for (int i = 0; i < size - 2; i++) {
      int first = nums[i], second = nums[i + 1], third = nums[i + 2];

      if ((first + third) * 2 == second) answer++;
    }
    return answer;
  }
};