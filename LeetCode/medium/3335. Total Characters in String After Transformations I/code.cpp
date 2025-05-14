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

// use dynamic programming
// time : O(N + T)
// space : O(1)
class Solution {
 public:
  int lengthAfterTransformations(string s, int t) {
    const int MOD = 1e9 + 7;

    int count[26] = {
        0,
    };
    for (char &c : s) {
      count[c - 'a']++;
    }

    for (int i = 0; i < t; i++) {
      int newCount[26] = {
          0,
      };

      for (int i = 0; i < 25; i++) {
        newCount[i + 1] = count[i];
        newCount[i + 1] %= MOD;
      }
      newCount[0] += count[25];
      newCount[0] %= MOD;
      newCount[1] += count[25];
      newCount[1] %= MOD;

      swap(newCount, count);
    }

    int answer = 0;
    for (int i = 0; i < 26; i++) {
      answer += count[i];
      answer %= MOD;
    }
    return answer;
  }
};