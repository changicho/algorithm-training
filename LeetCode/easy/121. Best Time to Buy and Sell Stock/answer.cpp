#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minimum = 10001;
    int answer = 0;
    for (int price : prices) {
      if (price < minimum) {
        minimum = price;
        continue;
      }
      answer = max(price - minimum, answer);
    }

    return answer;
  }
};