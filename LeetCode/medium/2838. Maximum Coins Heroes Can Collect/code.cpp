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

// use sort & prefix sum & binary search
// time : O((N + M) * log_2(M))
// space : O(N + M)
class Solution {
 public:
  vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters,
                                 vector<int>& coins) {
    int n = heroes.size(), m = monsters.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < m; i++) {
      arr.push_back({monsters[i], coins[i]});
    }
    sort(arr.begin(), arr.end());
    vector<long long> prefixes(m, 0);
    for (int i = 0; i < m; i++) {
      prefixes[i] = ((i > 0) ? prefixes[i - 1] : 0) + arr[i].second;
    }

    vector<long long> answer(n);
    for (int i = 0; i < n; i++) {
      int hero = heroes[i];

      int left = 0, right = m;
      while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].first <= hero) {
          // pick right
          left = mid + 1;
        } else {
          // pick left
          right = mid;
        }
      }
      int target = left - 1;

      answer[i] = target == -1 ? 0 : prefixes[target];
    }
    return answer;
  }
};