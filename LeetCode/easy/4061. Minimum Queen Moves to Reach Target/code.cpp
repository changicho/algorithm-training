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

// compare
// time : O(1)
// space : O(1)
class Solution {
 public:
  int minQueenMoves(vector<int>& source, vector<int>& target) {
    int hitCount = 0;

    int yDiff = abs(source[0] - target[0]);
    int xDiff = abs(source[1] - target[1]);
    if (yDiff == 0) hitCount++;
    if (xDiff == 0) hitCount++;
    if (yDiff == xDiff) hitCount++;

    if (hitCount >= 2) return 0;
    if (hitCount >= 1) return 1;
    return 2;
  }
};