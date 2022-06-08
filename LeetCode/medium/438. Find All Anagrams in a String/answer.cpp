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

// use sliding window
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> target(26, 0), counts(26, 0);
    for (char &c : p) {
      target[c - 'a']++;
    }

    int length = p.length();

    vector<int> indexes;
    for (int i = 0; i < s.length(); i++) {
      counts[s[i] - 'a']++;

      if (i - length >= 0) {
        counts[s[i - length] - 'a']--;
      }

      if (target == counts) {
        indexes.push_back(i - length + 1);
      }
    }

    return indexes;
  }
};