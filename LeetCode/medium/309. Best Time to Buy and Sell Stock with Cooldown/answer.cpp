#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int size = prices.size();
    vector<int> coolDownDp(size, 0);
    vector<int> buyDp(size, 0);
    vector<int> sellDp(size, 0);

    // restDp[i] // i번째 까지 최대값
    // buyDp[i]; // i번째까지 물건을 산 경우 중 가장 이익이 큰 경우
    // sellDp[i]; // i번째 가격에 주식을 팔았을 때의 값

    coolDownDp[0] = 0;
    buyDp[0] = -prices.front();
    sellDp[0] = 0;

    for (int i = 1; i < size; ++i) {
      buyDp[i] = max(buyDp[i - 1], coolDownDp[i - 1] - prices[i]);
      coolDownDp[i] = max(coolDownDp[i - 1], sellDp[i - 1]);
      sellDp[i] = buyDp[i - 1] + prices[i];
    }

    // 물건을 사는 경우는 절대 최대값이 될 수 없음
    int answer = max(coolDownDp.back(), sellDp.back());
    return answer;
  }
};

// use one pass

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int size = prices.size();

    int coolDown = 0;
    int buy = -prices.front();
    int sell = 0;

    for (int i = 1; i < size; ++i) {
      buy = max(buy, coolDown - prices[i]);
      coolDown = max(coolDown, sell);
      sell = buy + prices[i];
    }

    return max(sell, coolDown);
  }
};