#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  char firstUniqChar(string &str) {
    unordered_map<char, int> m;

    for (char c : str) {
      m[c] += 1;
    }

    for (char c : str) {
      if (m[c] == 1) return c;
    }
  }
};
