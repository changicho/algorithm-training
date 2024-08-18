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
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0, twenty = 0;

    for (int& bill : bills) {
      switch (bill) {
        case 5: {
          five++;
          break;
        }
        case 10: {
          five--;
          ten++;
          break;
        }
        case 20: {
          if (ten >= 1 && five >= 1) {
            ten--;
            five--;
            twenty++;
          } else {
            five -= 3;
            twenty++;
          }

          break;
        }
      }

      if (five < 0 || ten < 0) return false;
    }
    return true;
  }
};