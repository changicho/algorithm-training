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

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  bool isValidCode(string& code) {
    if (code.size() == 0) return false;
    for (char& c : code) {
      if (islower(c)) continue;
      if (isupper(c)) continue;
      if (isdigit(c)) continue;
      if (c == '_') continue;
      return false;
    }
    return true;
  }

 public:
  vector<string> validateCoupons(vector<string>& code,
                                 vector<string>& businessLine,
                                 vector<bool>& isActive) {
    unordered_set<string> validBusinesses = {"electronics", "grocery",
                                             "pharmacy", "restaurant"};

    int size = code.size();
    vector<vector<string>> arr;
    for (int i = 0; i < size; i++) {
      if (isActive[i] == false) continue;
      if (!isValidCode(code[i])) continue;
      if (!validBusinesses.count(businessLine[i])) continue;

      arr.push_back({businessLine[i], code[i]});
    }

    sort(arr.begin(), arr.end());

    vector<string> answer;
    for (vector<string>& a : arr) {
      answer.push_back(a[1]);
    }
    return answer;
  }
};