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

// use sort & binary search
// time : O((N + M) * log_2(N))
// space : O(N + M)
class Solution {
 public:
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    int size = items.size();

    sort(items.begin(), items.end());

    int maximum = 0;
    for (vector<int>& item : items) {
      maximum = max(maximum, item[1]);
      item[1] = maximum;
    }

    vector<int> answer;
    for (int& q : queries) {
      int left = 0, right = size;
      int target = -1;

      while (left < right) {
        int mid = left + (right - left) / 2;

        if (items[mid][0] <= q) {
          // pick right
          left = mid + 1;
          target = mid;
        } else {
          // pick left
          right = mid;
        }
      }

      if (target == -1) {
        answer.push_back(0);
      } else {
        answer.push_back(items[target][1]);
      }
    }
    return answer;
  }
};