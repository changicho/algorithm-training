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

using ll = long long;

// counting sort
// time : O(N)
// space : O(N)
class Solution {
 public:
  string smallestPalindrome(string s) {
    int count[26] = {
        0,
    };
    for (char& c : s) {
      count[c - 'a']++;
    }

    string a = "";
    string b = "";

    char center = 0;

    for (int i = 0; i < 26; i++) {
      int half = count[i] / 2;

      a += string(half, 'a' + i);
      b += string(half, 'a' + i);

      if (count[i] % 2 == 1) {
        center = ('a' + i);
      }
    }

    if (center) {
      a += center;
    }

    reverse(b.begin(), b.end());
    return a + b;
  }
};