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
long long check(vector<int> &diffs, vector<int> &times, int level) {
  long long ret = 0;

  int timePrev = 0;
  int size = diffs.size();
  for (int i = 0; i < size; i++) {
    if (diffs[i] <= level) {
      ret += times[i];
    } else {
      long long trial = diffs[i] - level;
      long long cost = trial * (timePrev + times[i]) + times[i];

      ret += cost;
    }
    timePrev = times[i];
  }
  return ret;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
  long long left = 1, right = INT_MAX;

  int answer = 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    long long curCost = check(diffs, times, mid);

    if (curCost <= limit) {
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