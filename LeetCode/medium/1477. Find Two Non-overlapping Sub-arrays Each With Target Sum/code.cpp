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

// prefix sum & dp
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minSumOfLengths(vector<int>& arr, int target) {
    int size = arr.size();
    unordered_map<int, int> pos;
    pos[0] = -1;

    vector<int> minLens(size);

    int sum = 0;
    int answer = INT_MAX;
    int minL = INT_MAX;

    for (int i = 0; i < size; i++) {
      sum += arr[i];

      if (pos.count(sum - target)) {
        int before = pos[sum - target];

        int len = i - before;

        if (before != -1 && minLens[before] != INT_MAX) {
          answer = min(answer, len + minLens[before]);
        }
        minL = min(minL, len);
      }

      minLens[i] = minL;
      pos[sum] = i;
    }
    if (answer == INT_MAX) return -1;
    return answer;
  }
};