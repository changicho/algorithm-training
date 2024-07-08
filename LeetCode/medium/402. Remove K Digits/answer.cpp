#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use monotonic stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  string removeKdigits(string num, int k) {
    int size = num.size();
    if (size == k) return "0";

    vector<char> stk;

    for (char &c : num) {
      while (k > 0 && !stk.empty() && stk.back() > c) {
        stk.pop_back();
        k--;
      }
      stk.push_back(c);
    }

    while (k > 0) {
      k--;
      stk.pop_back();
    }

    string answer = "";
    for (char &c : stk) {
      if (c == '0' && answer == "") continue;
      answer += c;
    }

    if (answer == "") return "0";
    return answer;
  }
};