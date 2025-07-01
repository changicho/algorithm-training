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

// use hash map (two pass)
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findLHS(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;

    unordered_map<int, int> um;
    for (int& num : nums) {
      um[num]++;
    }

    for (auto& [key, val] : um) {
      if (um.count(key + 1) == 0) continue;
      int cur = val + um[key + 1];

      answer = max(answer, cur);
    }

    return answer;
  }
};

// use hash map (one pass)
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findLHS(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;

    unordered_map<int, int> um;
    for (int& num : nums) {
      um[num]++;

      if (um.count(num + 1)) {
        int next = um[num] + um[num + 1];
        answer = max(answer, next);
      }
      if (um.count(num - 1)) {
        int prev = um[num] + um[num - 1];
        answer = max(answer, prev);
      }
    }

    return answer;
  }
};