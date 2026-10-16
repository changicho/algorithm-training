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

// brute force
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int sumCounts(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;

    for (int i = 0; i < size; i++) {
      unordered_set<int> us;
      for (int j = i; j < size; j++) {
        us.insert(nums[j]);

        answer += us.size() * us.size();
      }
    }
    return answer;
  }
};