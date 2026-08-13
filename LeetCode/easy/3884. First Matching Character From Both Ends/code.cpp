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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int firstMatchingIndex(string s) {
    int size = s.size();

    for (int i = 0; i <= size / 2; i++) {
      if (s[i] == s[size - 1 - i]) return i;
    }
    return -1;
  }
};