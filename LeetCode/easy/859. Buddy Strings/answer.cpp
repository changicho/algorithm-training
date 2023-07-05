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
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) return false;

    int size = s.size();

    int diffCount = 0;
    int sCount[26] = {
        0,
    };
    int goalCount[26] = {
        0,
    };
    int sMax = 0, goalMax = 0;

    for (int i = 0; i < size; i++) {
      sCount[s[i] - 'a']++;
      goalCount[goal[i] - 'a']++;
      sMax = max(sMax, sCount[s[i] - 'a']);
      goalMax = max(goalMax, goalCount[goal[i] - 'a']);

      if (s[i] != goal[i]) {
        diffCount++;
      }
    }

    for (int i = 0; i < 26; i++) {
      if (sCount[i] != goalCount[i]) return false;
    }

    if (diffCount == 2 || diffCount == 0 && sMax >= 2) return true;
    return false;
  }
};