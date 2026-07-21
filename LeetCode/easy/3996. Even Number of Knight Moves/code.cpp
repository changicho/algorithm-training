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

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  bool canReach(vector<int>& start, vector<int>& target) {
    return ((start[0] + start[1]) % 2) == ((target[0] + target[1]) % 2);
  }
};