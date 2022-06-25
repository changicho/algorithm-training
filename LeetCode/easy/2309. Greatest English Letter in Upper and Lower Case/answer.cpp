#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use count
// time : O(N)
// space : O(1)
class Solution {
 public:
  string greatestLetter(string s) {
    bool upper[26] = {
        0,
    };
    bool lower[26] = {
        0,
    };

    for (char &c : s) {
      if (islower(c)) {
        lower[c - 'a'] = true;
      } else if (isupper(c)) {
        upper[c - 'A'] = true;
      }
    }

    for (char c = 'Z'; c >= 'A'; c--) {
      if (upper[c - 'A'] && lower[c - 'A']) {
        return {
            c,
        };
      }
    }
    return "";
  }
};