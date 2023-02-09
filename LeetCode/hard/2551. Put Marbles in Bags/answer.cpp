#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N) + K)
// space : O(N)
class Solution {
 public:
  long long putMarbles(vector<int>& weights, int k) {
    int size = weights.size();
    if (size == k) return 0;

    vector<long long> diffs;
    for (int i = 0; i < size - 1; i++) {
      diffs.push_back(weights[i + 1] + weights[i]);
    }
    sort(diffs.begin(), diffs.end());

    long long minimum = 0;
    long long maximum = 0;
    for (int i = 0; i < k - 1; i++) {
      minimum += diffs[i];
      maximum += diffs[size - 2 - i];
    }

    return maximum - minimum;
  }
};