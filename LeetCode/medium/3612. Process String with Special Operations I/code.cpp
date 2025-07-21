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
// time : O(2^N)
// space : O(2^N)
class Solution {
 public:
  string processStr(string s) {
    string ret = "";

    for (char &c : s) {
      switch (c) {
        case '*': {
          if (ret.size() > 0) {
            ret.pop_back();
          }
          break;
        }
        case '#': {
          ret += ret;
          break;
        }
        case '%': {
          reverse(ret.begin(), ret.end());
          break;
        }
        default: {
          ret += c;
          break;
        }
      }
    }

    return ret;
  }
};