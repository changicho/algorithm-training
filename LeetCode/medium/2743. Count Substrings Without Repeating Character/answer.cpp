#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numberOfSpecialSubstrings(string s) {
    int size = s.size();

    int counts[26] = {0};
    int answer = 0;
    for (int l = 0, r = 0; r < size; r++) {
      counts[s[r] - 'a']++;

      while (l < r && counts[s[r] - 'a'] > 1) {
        counts[s[l] - 'a']--;
        l++;
      }

      answer += (r - l + 1);
    }

    return answer;
  }
};