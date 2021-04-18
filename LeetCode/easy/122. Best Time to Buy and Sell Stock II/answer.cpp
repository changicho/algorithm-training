#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// one pass

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int answer = 0;

    for (int i = 1; i < size; i++) {
      if (prices[i - 1] < prices[i]) {
        answer += prices[i] - prices[i - 1];
      }
    }
    return answer;
  }
};

// peek & valley

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int answer = 0;
    int i = 0;

    while (i < size - 1) {
      // find valley
      while (i < size - 1 && prices[i] >= prices[i + 1]) {
        i++;
      }
      int valley = prices[i];

      // find peek
      while (i < size - 1 && prices[i] <= prices[i + 1]) {
        i++;
      }
      int peek = prices[i];

      answer += peek - valley;
    }

    return answer;
  }
};