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

// brute force
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  int missingMultiple(vector<int>& nums, int k) {
    bool b[101] = {
        false,
    };
    for (int& num : nums) {
      b[num] = true;
    }

    int i = k;
    while (i <= 100) {
      if (b[i] == false) return i;
      i += k;
    }
    return i;
  }
};