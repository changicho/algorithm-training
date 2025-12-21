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

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    int size = prices.size();

    vector<long long> pricePrefixes(size + 1, 0);
    vector<long long> profitPrefixes(size + 1, 0);
    for (int i = 0; i < size; i++) {
      pricePrefixes[i + 1] = pricePrefixes[i] + prices[i];
      profitPrefixes[i + 1] = profitPrefixes[i] + prices[i] * strategy[i];
    }

    long long answer = profitPrefixes[size];
    for (int i = 0; i <= size - k; i++) {
      int left = i, right = i + k - 1;
      long long leftPart = profitPrefixes[left];
      long long rightPart = profitPrefixes[size] - profitPrefixes[right + 1];

      long long midPart = pricePrefixes[right + 1] - pricePrefixes[right - k / 2 + 1];

      long long cur = leftPart + midPart + rightPart;
      answer = max(answer, cur);
    }
    return answer;
  }
};