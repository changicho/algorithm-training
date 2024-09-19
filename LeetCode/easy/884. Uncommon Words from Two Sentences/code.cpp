#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash map
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  vector<string> split(string &s) {
    vector<string> ret;

    stringstream ss(s);
    string temp;
    while (ss >> temp) {
      ret.push_back(temp);
    }

    return ret;
  }

 public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    vector<string> v1 = split(s1), v2 = split(s2);

    unordered_map<string, int> um;
    for (string &w : v1) {
      um[w]++;
    }
    for (string &w : v2) {
      um[w]++;
    }

    vector<string> answer;
    for (auto [key, val] : um) {
      if (val == 1) answer.push_back(key);
    }
    return answer;
  }
};