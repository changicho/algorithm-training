#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// depth count
// time : O(N)
// space : O(N)
class Solution {
 public:
  string removeOuterParentheses(string s) {
    string answer = "";
    int depth = 0;

    for (char& c : s) {
      if (c == '(') {
        if (depth > 0) {
          answer += c;
        }
        depth++;
      } else {
        if (depth > 1) {
          answer += c;
        }
        depth--;
      }
    }
    return answer;
  }
};