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

// use count odd
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool canConstruct(string s, int k) {
    if (s.size() < k) return false;
    int count[26] = {
        0,
    };
    for (char &c : s) {
      count[c - 'a']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
      oddCount += count[i] % 2;
    }

    return oddCount <= k;
  }
};