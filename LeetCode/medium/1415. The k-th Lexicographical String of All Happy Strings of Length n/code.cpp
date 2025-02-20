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

// use recursive and sort
// time : O(N * 2^N)
// space : O(N * 2^N)
class Solution {
 private:
  vector<string> ret;

  void recursive(int size, string &s) {
    if (size == s.size()) {
      ret.push_back(s);
      return;
    }

    for (char c = 'a'; c <= 'c'; c++) {
      if (!s.empty() && s.back() == c) continue;

      s.push_back(c);
      recursive(size, s);
      s.pop_back();
    }
  }

 public:
  string getHappyString(int n, int k) {
    string temp = "";

    recursive(n, temp);

    if (ret.size() <= (k - 1)) return "";
    sort(ret.begin(), ret.end());

    return ret[k - 1];
  }
};