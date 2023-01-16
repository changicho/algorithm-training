#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long minimumHealth(vector<int>& damage, int armor) {
    int size = damage.size();

    long long health = 0;

    int maxI = 0;
    for (int i = 0; i < size; i++) {
      if (damage[i] > damage[maxI]) {
        maxI = i;
      }
    }

    damage[maxI] = max(0, damage[maxI] - armor);

    for (int& d : damage) {
      health += d;
    }

    return health + 1;
  }
};