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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> separateDigits(vector<int>& nums) {
    vector<int> answer;

    for (int& num : nums) {
      bool hasFind = false;
      for (int digit = 1e5; digit >= 1; digit /= 10) {
        if (!hasFind && digit > num) continue;
        hasFind = true;

        answer.push_back(num / digit);
        num %= digit;
      }
    }

    return answer;
  }
};