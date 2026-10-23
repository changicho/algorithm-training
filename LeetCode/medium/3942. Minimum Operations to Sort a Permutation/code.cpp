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

using ll = long long;

// case check
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int size = nums.size();

    int minimum = nums[0];
    int minI = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] < minimum) {
        minI = i;
        minimum = nums[i];
      }
    }

    bool alreadySorted = true;
    // check already sorted
    for (int i = 0; i < size - 1; i++) {
      if (nums[(minI + i) % size] > nums[(minI + i + 1) % size]) {
        alreadySorted = false;
        break;
      }
    }
    if (alreadySorted) return min(minI, size - 1 - minI + 1 + 2);

    // check is sorted by reverse
    for (int i = 0; i < size - 1; i++) {
      if (nums[(minI - i + size) % size] > nums[(minI - i - 1 + size) % size])
        return -1;
    }

    return 1 + min(minI + 1, size - 1 - minI);
  }
};