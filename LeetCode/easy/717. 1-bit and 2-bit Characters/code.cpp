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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    int size = bits.size();
    int i = 0;

    while (i < size - 1) {
      if (bits[i] == 0) {
        i++;
      } else {
        i += 2;
      }
    }

    return i == size - 1;
  }
};