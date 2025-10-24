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
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  bool hasSameDigits(string s) {
    while (s.size() > 2) {
      string newS = "";

      int size = s.size();
      for (int i = 0; i < size - 1; i++) {
        int cur = (s[i] - '0') + (s[i + 1] - '0');
        cur %= 10;

        newS += cur + '0';
      }

      s = newS;
    }

    if (s.size() < 2) return false;
    return s[0] == s[1];
  }
};