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

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int size = arr.size();

    int minDiff = INT_MAX;
    for (int i = 0; i < size - 1; i++) {
      int diff = arr[i + 1] - arr[i];
      minDiff = min(minDiff, diff);
    }

    vector<vector<int>> answer;
    for (int i = 0; i < size - 1; i++) {
      int diff = arr[i + 1] - arr[i];

      if (diff == minDiff) {
        answer.push_back({arr[i], arr[i + 1]});
      }
    }
    return answer;
  }
};