#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & one pass
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    int size = hand.size();

    if (size % groupSize != 0) return false;

    sort(hand.begin(), hand.end());
    unordered_map<int, int> counts;
    for (int &num : hand) {
      counts[num]++;
    }

    for (int &num : hand) {
      if (counts[num] == 0) continue;

      for (int i = 0; i < groupSize; i++) {
        if (counts[num + i] == 0) return false;
        counts[num + i]--;
      }
    }

    return true;
  }
};
