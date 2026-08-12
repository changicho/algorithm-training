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

// sort & greedy
// time : O(N * log_2(N) + M * log_2(M))
// space : O(N + M)
class Solution {
 public:
  double minPrice(vector<int>& prices, vector<int>& discounts) {
    sort(prices.begin(), prices.end(), greater<int>());
    sort(discounts.begin(), discounts.end(), greater<int>());

    int size1 = prices.size(), size2 = discounts.size();
    int limit = min(size1, size2);

    double answer = 0.0;
    for (int i = 0; i < limit; i++) {
      double cur = prices[i] * (100.0 - discounts[i]) / 100;

      answer += cur;
    }

    for (int i = limit; i < size1; i++) {
      answer += prices[i];
    }

    return answer;
  }
};