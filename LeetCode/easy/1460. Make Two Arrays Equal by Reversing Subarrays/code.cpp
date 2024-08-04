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

// use counts
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> counts;

    for (int& num : target) {
      counts[num]++;
    }

    for (int& num : arr) {
      counts[num]--;

      if (counts[num] < 0) return false;
    }

    return true;
  }
};