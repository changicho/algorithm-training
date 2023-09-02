#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minTaps(int n, vector<int>& ranges) {
    int size = ranges.size();

    vector<pair<int, int>> arr;
    for (int i = 0; i < size; i++) {
      arr.push_back({i - ranges[i], i + ranges[i]});
    }

    sort(arr.begin(), arr.end());

    int right = 0;
    int index = 0;

    int answer = 0;
    while (index < size && right < n) {
      int next = -1;
      while (index < size && arr[index].first <= right) {
        if (right <= arr[index].second) {
          next = max(next, arr[index].second);
        }
        index++;
      }

      if (next == -1) return -1;
      answer++;
      right = next;
    }

    if (answer == 0) return -1;
    return answer;
  }
};

// use dynamic programming
// time : O(N * M)
// space : O(N)
class Solution {
 public:
  int minTaps(int n, vector<int>& ranges) {
    const int MAX = 1e9;
    vector<int> dp(n + 1, MAX);

    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
      int left = max(0, i - ranges[i]);
      int right = min(n, i + ranges[i]);

      for (int j = left; j <= right; j++) {
        dp[right] = min(dp[right], dp[j] + 1);
      }
    }

    if (dp[n] == MAX) return -1;

    return dp[n];
  }
};