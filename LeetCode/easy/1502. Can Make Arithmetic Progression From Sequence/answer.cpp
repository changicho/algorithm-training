#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & one pass
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
    for (int i = 1; i < arr.size(); i++) {
      int curDiff = arr[i] - arr[i - 1];

      if (curDiff != diff) return false;
    }
    return true;
  }
};