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
// time : O(N)
// space : O(1)
class Solution {
 public:
  int scoreDifference(vector<int>& nums) {
    int size = nums.size();
    int first = 0;
    int second = 0;

    bool isFirst = true;
    for (int i = 0; i < size; i++) {
      int cur = nums[i];

      if (cur % 2 == 1) {
        isFirst = !isFirst;
      }
      if (i % 6 == 5) {
        isFirst = !isFirst;
      }

      if (isFirst) {
        first += cur;
      } else {
        second += cur;
      }
    }

    return first - second;
  }
};