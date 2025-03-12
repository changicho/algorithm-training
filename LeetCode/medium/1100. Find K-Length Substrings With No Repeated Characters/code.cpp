#include <algorithm>
#include <climits>
#include <cmath>
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

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numKLenSubstrNoRepeats(string s, int k) {
    int size = s.size();
    int counts[26] = {
        0,
    };

    int uniques = 0;
    int answer = 0;
    for (int l = 0, r = 0; r < size; r++) {
      if (counts[s[r] - 'a'] == 0) {
        uniques++;
      }
      counts[s[r] - 'a']++;

      if (r - l + 1 > k) {
        counts[s[l] - 'a']--;
        if (counts[s[l] - 'a'] == 0) {
          uniques--;
        }
        l++;
      }

      if (uniques == k) {
        answer++;
      }
    }
    return answer;
  }
};