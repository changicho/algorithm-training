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

// use stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  string makeFancyString(string s) {
    string ret = "";

    for (char &c : s) {
      int size = ret.size();
      if (size >= 2) {
        if (ret[size - 1] == ret[size - 2] && c == ret[size - 1]) {
          continue;
        }
      }

      ret += c;
    }
    return ret;
  }
};