#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  string trimTrailingVowels(string s) {
    bool isVowel[26] = {false};
    isVowel['a' - 'a'] = true;
    isVowel['e' - 'a'] = true;
    isVowel['i' - 'a'] = true;
    isVowel['o' - 'a'] = true;
    isVowel['u' - 'a'] = true;

    int size = s.size();
    int target = -1;
    for (int i = size - 1; i >= 0; i--) {
      if (!isVowel[s[i] - 'a']) {
        target = i;
        break;
      }
    }

    return s.substr(0, target + 1);
  }
};