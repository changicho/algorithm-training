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

// case
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minOperations(string s) {
    int size = s.size();
    char maximum = 'a', minimum = 'z';

    bool isSorted = true;
    for (int i = 0; i < size; i++) {
      char& c = s[i];
      maximum = max(maximum, c);
      minimum = min(minimum, c);

      if (i + 1 < size && s[i] > s[i + 1]) {
        isSorted = false;
      }
    }
    if (isSorted) {
      return 0;
    }
    if (size == 2) {
      return -1;
    }
    if (s[0] == minimum || s[size - 1] == maximum) {
      return 1;
    }
    for (int i = 1; i < size - 1; i++) {
      if (s[i] == minimum || s[i] == maximum) {
        return 2;
      }
    }
    // cba
    return 3;
  }
};