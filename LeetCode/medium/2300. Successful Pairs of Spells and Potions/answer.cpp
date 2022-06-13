#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O((N + M) * log_2(M))
// space : O(N)
class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    int size = spells.size();
    vector<int> ret(size, 0);

    sort(potions.begin(), potions.end());

    for (int i = 0; i < size; i++) {
      int cur = spells[i];
      double target = (double)success / cur;

      int idx =
          lower_bound(potions.begin(), potions.end(), target) - potions.begin();

      ret[i] = potions.size() - idx;
    }
    return ret;
  }
};