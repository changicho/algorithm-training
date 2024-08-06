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

// use two pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  string kthDistinct(vector<string> &arr, int k) {
    unordered_map<string, int> counts;

    for (string &s : arr) {
      counts[s]++;
    }

    for (string &s : arr) {
      if (counts[s] > 1) continue;

      k--;
      if (k == 0) return s;
    }

    return "";
  }
};