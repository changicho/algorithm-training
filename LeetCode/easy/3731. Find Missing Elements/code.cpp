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

// hash set & iteration
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  vector<int> findMissingElements(vector<int>& nums) {
    int left = nums[0], right = nums[0];

    bool b[101] = {
        0,
    };

    for (int& num : nums) {
      b[num] = true;

      left = min(left, num);
      right = max(right, num);
    }

    vector<int> answer;
    for (int i = left; i <= right; i++) {
      if (b[i] == false) answer.push_back(i);
    }
    return answer;
  }
};