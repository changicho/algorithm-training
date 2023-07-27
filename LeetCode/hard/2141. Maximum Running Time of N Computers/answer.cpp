#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search with sort
// time : O((N + M) * log_2(N))
// space : O(N)
class Solution {
 private:
  bool check(int n, vector<int>& b, long long target) {
    if (b.size() < n) return false;

    long long sum = 0, fill = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] < target) fill += target - b[i];
    }
    for (int i = n; i < b.size(); i++) {
      sum += b[i];
    }

    if (fill <= sum) return true;
    return false;
  }

 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    sort(batteries.begin(), batteries.end(), greater<int>());

    long long answer = 0;
    long long left = 0, right = 1e14 + 1;
    while (left < right) {
      long long mid = left + (right - left) / 2;

      if (check(n, batteries, mid)) {
        // pick right
        answer = mid;
        left = mid + 1;
      } else {
        // pick left;
        right = mid;
      }
    }

    return answer;
  }
};

// use binary search
// time : O(M * log_2(N))
// space : O(N)
class Solution {
 private:
  // If the power of a battery is smaller than target,
  // we can use all of its power.
  // If the power of a battery is larger than target,
  // we can only use target power from it.
  bool check(int n, vector<int>& batteries, long long target) {
    long long extra = 0;
    for (int& b : batteries) {
      extra += min((long long)b, target);
    }

    return extra >= target * n;
  }

 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    long long answer = 0;
    long long left = 0, right = 1e14 + 1;
    while (left < right) {
      long long mid = left + (right - left) / 2;

      if (check(n, batteries, mid)) {
        // pick right
        answer = mid;
        left = mid + 1;
      } else {
        // pick left;
        right = mid;
      }
    }

    return answer;
  }
};