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
  int minSwaps(string s) {
    stack<char> stk;

    for (char &c : s) {
      if (!stk.empty() && c == ']' && stk.top() == '[') {
        stk.pop();
        continue;
      }
      stk.push(c);
    }

    int count = stk.size() / 2;

    return (count + 1) / 2;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minSwaps(string s) {
    int count = 0;

    for (char &c : s) {
      switch (c) {
        case '[': {
          count++;
          break;
        }
        case ']': {
          if (count > 0) count--;
          break;
        }
      }
    }

    return (count + 1) / 2;
  }
};