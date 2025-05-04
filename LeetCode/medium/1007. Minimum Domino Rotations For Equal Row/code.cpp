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

// use brute force
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int size = tops.size();

    int answer = INT_MAX;
    for (int target = 1; target <= 6; target++) {
      int swapTop = 0;
      int swapBottom = 0;

      bool isPossible = true;
      for (int i = 0; i < size; i++) {
        if (tops[i] != target && bottoms[i] == target) {
          swapBottom++;
        }
        if (tops[i] == target && bottoms[i] != target) {
          swapTop++;
        }

        if (tops[i] != target && bottoms[i] != target) {
          isPossible = false;
          break;
        }
      }

      if (!isPossible) continue;

      answer = min({answer, swapTop, swapBottom});
    }

    return answer == INT_MAX ? -1 : answer;
  }
};
