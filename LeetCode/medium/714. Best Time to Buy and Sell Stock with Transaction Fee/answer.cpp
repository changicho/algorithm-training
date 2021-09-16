#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int size = prices.size();

    vector<int> buyDp(size, 0);  // i번째 까지 물건을 샀을 때의 최대값
    vector<int> sellDp(size, 0);  // i번째 까지 물건을 팔았을 때의 최대값

    buyDp.front() = -prices.front();

    for (int i = 1; i < size; i++) {
      buyDp[i] = max(buyDp[i - 1], sellDp[i - 1] - prices[i]);
      sellDp[i] = max(sellDp[i - 1], buyDp[i - 1] + prices[i] - fee);
    }

    return sellDp.back();
  }
};

// use one pass

class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int size = prices.size();
    int sell = 0, buy = -prices.front();

    for (int i = 1; i < size; ++i) {
      sell = max(sell, buy + prices[i] - fee);
      buy = max(buy, sell - prices[i]);
    }

    return sell;
  }
};