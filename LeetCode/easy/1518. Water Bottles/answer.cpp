#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(log_M(N))
// space : O(1)
class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int full = numBottles, empty = 0;

    int answer = 0;

    while (full > 0 || empty > 0) {
      answer += full;
      empty += full;
      full = 0;

      if (empty < numExchange) break;

      int div = empty / numExchange;

      full += div;
      empty -= div * numExchange;
    }

    return answer;
  }
};