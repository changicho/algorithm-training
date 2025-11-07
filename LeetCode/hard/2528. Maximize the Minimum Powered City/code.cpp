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

// use binary search & diff
// time : O(N \* log(M))
// space : O(N)
class Solution {
 private:
  bool check(long long val, vector<long long>& count, int k, int size, int r) {
    vector<long long> diff = count;
    long long sum = 0;
    long long remaining = k;

    for (int i = 0; i < size; i++) {
      sum += diff[i];
      if (sum < val) {
        long long add = val - sum;
        if (remaining < add) {
          return false;
        }
        remaining -= add;
        int end = min(size, i + 2 * r + 1);
        diff[end] -= add;
        sum += add;
      }
    }
    return true;
  };

 public:
  long long maxPower(vector<int>& stations, int r, int k) {
    int size = stations.size();

    vector<long long> count(size + 1);

    for (int i = 0; i < size; i++) {
      int left = max(0, i - r);
      int right = min(size, i + r + 1);
      count[left] += stations[i];
      count[right] -= stations[i];
    }

    long long left = *min_element(stations.begin(), stations.end());
    long long right = accumulate(stations.begin(), stations.end(), 0LL) + k + 1;
    long long answer = 0;

    while (left < right) {
      long long mid = left + (right - left) / 2;

      if (check(mid, count, k, size, r)) {
        answer = mid;
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return answer;
  }
};
