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

// index store
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minimumDistance(vector<int>& nums) {
    int size = nums.size();
    vector<pair<int, int>> indexes(size + 1, {-1, -1});

    int answer = INT_MAX;
    for (int i = 0; i < size; i++) {
      int cur = nums[i];

      if (indexes[cur].first != -1) {
        int first = indexes[cur].first, second = indexes[cur].second, third = i;

        int diff = second - first + third - second + third - first;
        answer = min(diff, answer);
      }

      indexes[cur].first = indexes[cur].second;
      indexes[cur].second = i;
    }

    if (answer == INT_MAX) return -1;
    return answer;
  }
};