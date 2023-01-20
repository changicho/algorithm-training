#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int appendCharacters(string s, string t) {
    int idx = 0;

    for (int i = 0; i < s.size() && idx < t.size(); i++) {
      if (s[i] == t[idx]) idx++;
    }

    return t.size() - idx;
  }
};