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

// use prefix sum
// time : O(N + Q)
// space : O(N + Q)
class Solution {
 public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int size = nums.size();

    vector<int> prefix(size + 1);
    prefix[1] = 1;
    for (int i = 1; i < size; i++) {
      prefix[i] = prefix[i - 1] + ((nums[i] % 2) != (nums[i - 1] % 2));
    }

    vector<bool> answer;
    for (vector<int>& q : queries) {
      int left = q[0], right = q[1];
      int len = right - left + 1;

      int cur = prefix[right] - prefix[left];

      answer.push_back(cur == (len - 1));
    }
    return answer;
  }
};