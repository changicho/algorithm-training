#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int lengthS = s.length(), lengthP = p.length();
    if (lengthS < lengthP) {
      return {};
    }

    vector<int> res;
    vector<int> countS(26, 0), countP(26, 0);

    for (int i = 0; i < lengthP; ++i) {
      countP[p[i] - 'a'] += 1;
      countS[s[i] - 'a'] += 1;
    }

    for (int left = 0; left < lengthS - lengthP; ++left) {
      int right = left + lengthP;

      if (countP == countS) {
        res.push_back(left);
      }

      countS[s[right] - 'a'] += 1;
      countS[s[left] - 'a'] -= 1;
    }

    if (countP == countS) {
      res.push_back(s.length() - p.length());
    }

    return res;
  }
};