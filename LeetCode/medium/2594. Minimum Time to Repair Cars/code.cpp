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
  bool check(long long time, vector<int> &ranks, int cars) {
    long long count = 0;

    for (int &r : ranks) {
      long long d = sqrt(time / r);
      count += d;
    }

    return count >= cars;
  }

 public:
  long long repairCars(vector<int> &ranks, int cars) {
    long long answer = 0;

    long long left = 1, right = 1e14 + 1;

    while (left < right) {
      long long mid = left + (right - left) / 2;

      if (check(mid, ranks, cars)) {
        // pick left part
        right = mid;
      } else {
        // pick right part
        left = mid + 1;
      }
    }
    return left;
  }
};