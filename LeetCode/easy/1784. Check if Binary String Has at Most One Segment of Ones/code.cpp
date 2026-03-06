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
// space : O(1)
class Solution {
 public:
  bool checkOnesSegment(string s) {
    int size = s.size();
    int count = 0;

    char before = '0';
    for (int i = 0; i < size; i++) {
      if (s[i] == '0' && before == '1') {
        count++;

        if (count > 1) return false;
      }
      before = s[i];
    }
    if (before == '1') count++;

    return count <= 1;
  }
};