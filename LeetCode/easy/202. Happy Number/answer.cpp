#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> s;

    while (s.find(n) == s.end()) {
      if (n == 1) {
        return true;
      }
      s.insert(n);

      int cur = 0;
      while (n) {
        int target = n % 10;
        cur += target * target;
        n /= 10;
      }
      n = cur;
    }

    return false;
  }
};
