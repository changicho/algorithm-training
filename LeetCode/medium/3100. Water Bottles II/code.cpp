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

// use simulation
// time : O(sqrt(N))
// space : O(1)
class Solution {
 public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int answer = 0;
    int drink = 0;
    while (numBottles > 0) {
      drink += numBottles;
      answer += numBottles;
      numBottles = 0;
      while (drink >= numExchange) {
        drink -= numExchange;
        numBottles++;
        numExchange++;
      }
    }
    return answer;
  }
};