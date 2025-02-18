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

// use stack brute force
// time : O(N * M)
// space : O(N)
class Solution {
 private:
  bool check(string &s, string &part) {
    if (s.size() < part.size()) return false;

    return s.substr(s.size() - part.size()) == part;
  }

 public:
  string removeOccurrences(string s, string part) {
    string answer = "";
    for (char &c : s) {
      answer.push_back(c);

      if (check(answer, part)) {
        answer.erase(answer.size() - part.size());
      }
    }
    return answer;
  }
};