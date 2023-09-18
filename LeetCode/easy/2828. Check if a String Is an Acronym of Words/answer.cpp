#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool isAcronym(vector<string>& words, string s) {
    string cur = "";
    for (string& w : words) {
      cur += w.front();
    }
    return cur == s;
  }
};