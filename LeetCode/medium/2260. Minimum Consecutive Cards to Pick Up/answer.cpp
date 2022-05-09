#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash map & one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minimumCardPickup(vector<int>& cards) {
    int size = cards.size();
    unordered_map<int, int> lasts;

    int minimum = INT_MAX;

    for (int i = 0; i < size; i++) {
      int card = cards[i];

      if (lasts.count(card) > 0) {
        minimum = min(minimum, i - lasts[card] + 1);
      }

      lasts[card] = i;
    }

    return minimum == INT_MAX ? -1 : minimum;
  }
};