#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use countint
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  int minSteps(string s, string t) {
    vector<int> countS(26, 0), countT(26, 0);

    for (char &c : s) {
      countS[c - 'a']++;
    }
    for (char &c : t) {
      countT[c - 'a']++;
    }

    int step = 0;
    for (int i = 0; i < 26; i++) {
      if (countS[i] == countT[i]) continue;

      int diff = abs(countS[i] - countT[i]);
      step += diff;
    }
    return step;
  }
};