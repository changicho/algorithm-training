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

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  long long countBadPairs(vector<int>& nums) {
    long long answer = 0;

    int size = nums.size();
    unordered_map<int, int> counts;

    for (int i = 0; i < size; i++) {
      int cur = i - nums[i];

      answer += i - counts[cur];
      counts[cur]++;
    }
    return answer;
  }
};