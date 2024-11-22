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
  bool calc(int n, vector<int> &quantities, int limit) {
    int count = 0;
    for (int &q : quantities) {
      count += q / limit;
      if (q % limit > 0) count++;
    }
    return count <= n;
  }

 public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    int left = 1,
        right = *max_element(quantities.begin(), quantities.end()) + 1;

    int answer = -1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (calc(n, quantities, mid)) {
        // pick left
        right = mid;
        answer = mid;
      } else {
        // pick right
        left = mid + 1;
      }
    }
    return answer;
  }
};