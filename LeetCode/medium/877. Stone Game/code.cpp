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

// sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    int size = piles.size();

    sort(piles.begin(), piles.end());
    int alice = 0, bob = 0;
    for (int i = size - 1; i >= 0; i -= 2) {
      alice += piles[i];
      bob += piles[i - 1];
    }

    return alice >= bob;
  }
};

// greedy
// time : O(1)
// space : O(1)
class Solution {
 public:
  bool stoneGame(vector<int>& piles) { return true; }
};