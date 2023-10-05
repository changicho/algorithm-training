#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool winnerOfGame(string colors) {
    int aCount = 0, bCount = 0;
    int aRemove = 0, bRemove = 0;

    for (char &c : colors) {
      if (c == 'A') {
        bRemove += max(bCount - 2, 0);
        bCount = 0;
        aCount++;
      } else {
        aRemove += max(aCount - 2, 0);
        aCount = 0;
        bCount++;
      }
    }
    aRemove += max(aCount - 2, 0);
    bRemove += max(bCount - 2, 0);

    if (aRemove > bRemove) return true;
    return false;
  }
};