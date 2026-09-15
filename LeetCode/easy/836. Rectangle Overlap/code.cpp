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
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    bool xFlag = rec2[0] < rec1[2] && rec1[0] < rec2[2];
    bool yFlag = rec2[1] < rec1[3] && rec1[1] < rec2[3];

    return xFlag && yFlag;
  }
};