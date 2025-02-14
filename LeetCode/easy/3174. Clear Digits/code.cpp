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
  string clearDigits(string s) {
    string ret = "";
    for (char &c : s) {
      if (isdigit(c)) {
        ret.pop_back();
      } else {
        ret.push_back(c);
      }
    }

    return ret;
  }
};

// use stack (in place)
// time : O(N)
// space : O(1)
class Solution {
 public:
  string clearDigits(string s) {
    int size = s.size();

    int length = 0;
    for (int i = 0; i < size; i++) {
      if (isdigit(s[i])) {
        length = max(length - 1, 0);
      } else {
        s[length] = s[i];
        length++;
      }
    }

    s.resize(length);

    return s;
  }
};