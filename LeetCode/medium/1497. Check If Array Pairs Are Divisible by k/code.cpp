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

// use mod count
// time : O(N)
// space : O(K)
class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    vector<int> mods(k, 0);

    for (int& num : arr) {
      int mod = num % k;
      mod = (mod + k) % k;

      int other = (k - mod) % k;

      if (mods[other] > 0) {
        mods[other]--;
      } else {
        mods[mod]++;
      }
    }

    for (int i = 0; i < k; i++) {
      if (mods[i] > 0) return false;
    }
    return true;
  }
};