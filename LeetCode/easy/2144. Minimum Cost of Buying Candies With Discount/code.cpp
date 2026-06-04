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

// sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    int answer = 0;
    int size = cost.size();

    sort(cost.begin(), cost.end());

    for (int i = size - 1; i >= 0; i--) {
      answer += cost[i];
      i--;
      if (i < 0) break;
      answer += cost[i];
      i--;
    }

    return answer;
  }
};