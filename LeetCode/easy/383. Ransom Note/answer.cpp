#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use counts

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> counts(26, 0);

    // count all alphabet in magazine
    for (char &c : magazine) {
      counts[c - 'a'] += 1;
    }

    // iterate all alphabet in ransomNote
    for (char &c : ransomNote) {
      // decrease current alphabet count in magazine
      counts[c - 'a'] -= 1;
      // if current count is lower than 0,
      // that means there are no current alphabet in magazine
      if (counts[c - 'a'] < 0) return false;
    }

    return true;
  }
};