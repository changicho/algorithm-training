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

// hash map & one pass
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> um;
    for (vector<string>& cur : knowledge) {
      string key = cur[0];
      string val = cur[1];
      um[key] = val;
    }

    string answer = "";
    bool isBracket = false;
    string temp = "";

    for (char& c : s) {
      if (c == '(') {
        isBracket = true;
        continue;
      } else if (c == ')') {
        if (um.count(temp)) {
          answer += um[temp];
        } else {
          answer += "?";
        }

        temp = "";
        isBracket = false;
        continue;
      }

      if (isBracket) {
        temp += c;
      } else {
        answer += c;
      }
    }

    return answer;
  }
};