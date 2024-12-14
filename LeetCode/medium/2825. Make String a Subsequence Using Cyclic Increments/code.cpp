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

// use two pointer
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  bool canMakeSubsequence(string str1, string str2) {
    int size1 = str1.size(), size2 = str2.size();

    for (int i1 = 0, i2 = 0; i1 < size1; i1++) {
      char cur = str1[i1];
      char next = cur + 1;
      if (next > 'z') next = 'a';

      if (i2 < size2 && (str2[i2] == cur || str2[i2] == next)) {
        i2++;
      }

      if (i2 == size2) return true;
    }
    return false;
  }
};