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

// use brute force
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<string> split(string &s) {
    stringstream ss(s);
    string temp;
    vector<string> ret;

    while (ss >> temp) {
      ret.push_back(temp);
    }
    return ret;
  }

 public:
  string generateTag(string caption) {
    string ret = "#";

    vector<string> tokens = split(caption);

    for (string &token : tokens) {
      int size = token.size();
      ret += toupper(token[0]);

      for (int i = 1; i < size; i++) {
        ret += tolower(token[i]);
      }
    }

    if (ret.size() > 1) {
      ret[1] = tolower(ret[1]);
    }

    return ret.substr(0, 100);
  }
};