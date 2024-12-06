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
// time : O(1)
// space : O(1)
class Solution {
 public:
  bool canAliceWin(int n) {
    int alice = 10, bob = 9;

    while (n > 0) {
      if (n < alice) return false;
      n -= alice;
      alice -= 2;

      if (n < bob) return true;
      n -= bob;
      bob -= 2;
    }
    return false;
  }
};