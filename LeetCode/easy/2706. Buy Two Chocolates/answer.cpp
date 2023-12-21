#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int buyChoco(vector<int>& prices, int money) {
    int first = INT_MAX, second = INT_MAX;
    for (int& p : prices) {
      if (p < first) {
        second = first;
        first = p;
      } else if (p < second) {
        second = p;
      }
    }

    if (first + second > money) return money;
    return money - (first + second);
  }
};