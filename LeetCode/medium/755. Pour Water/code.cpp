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

// simulation
// time : O(N * V)
// space : O(1)
class Solution {
 public:
  vector<int> pourWater(vector<int>& heights, int volume, int k) {
    int size = heights.size();

    for (int i = 0; i < volume; i++) {
      int cur = heights[k];
      int target = k;
      for (int i = k - 1; i >= 0; i--) {
        if (heights[i] > heights[target])
          break;
        else if (heights[i] < heights[target]) {
          target = i;
        }
      }

      if (target == k) {
        for (int i = k + 1; i < size; i++) {
          if (heights[i] > heights[target])
            break;
          else if (heights[i] < heights[target]) {
            target = i;
          }
        }
      }

      heights[target]++;
    }

    return heights;
  }
};