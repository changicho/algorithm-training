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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int finalValueAfterOperations(vector<string>& operations) {
    int x = 0;

    for (string& oper : operations) {
      if (oper == "--X" || oper == "X--") {
        x--;
      } else if (oper == "++X" || oper == "X++") {
        x++;
      }
    }

    return x;
  }
};