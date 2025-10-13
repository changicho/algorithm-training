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

// use binary search
// time : O(N * log_2(M))
// space : O(1)
class Solution {
 private:
  bool check(vector<int>& stations, double limit, int k) {
    int size = stations.size();
    int used = 0;

    for (int i = 0; i < size - 1; i++) {
      int diff = stations[i + 1] - stations[i];

      used += (int)(diff / limit);
    }
    return used <= k;
  }

 public:
  double minmaxGasDist(vector<int>& stations, int k) {
    int size = stations.size();

    double left = 0, right = 1e8;
    double answer = right;
    while (right - left > 1e-6) {
      double mid = left + (right - left) / 2;

      if (check(stations, mid, k)) {
        right = mid;
        answer = mid;
      } else {
        left = mid;
      }
    }
    return answer;
  }
};