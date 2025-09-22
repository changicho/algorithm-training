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

// use sort & dynamic programming
// time : O(N \* (log_2(N) + K))
// space : O(N + K)
class Solution {
 public:
  vector<bool> subsequenceSumAfterCapping(vector<int> &arr, int k) {
    int size = arr.size();
    sort(arr.begin(), arr.end());
    bool isPossible[4001] = {
        false,
    };

    vector<bool> answer;
    isPossible[0] = true;

    for (int i = 0, x = 1; x <= size; x++) {
      while (i < size && arr[i] < x) {
        for (int sum = k; sum >= arr[i]; sum--) {
          isPossible[sum] |= isPossible[sum - arr[i]];
        }

        i++;
      }

      bool canMake = false;
      int bigCount = size - i;
      for (int count = 0; count <= bigCount && count * x <= k; count++) {
        if (isPossible[k - count * x]) {
          canMake = true;
          break;
        }
      }

      answer.push_back(canMake);
    }
    return answer;
  }
};