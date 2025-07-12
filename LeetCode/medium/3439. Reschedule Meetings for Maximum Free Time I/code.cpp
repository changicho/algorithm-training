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

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                  vector<int>& endTime) {
    int size = startTime.size();
    vector<int> prefixSum(size + 1);
    for (int i = 0; i < size; i++) {
      prefixSum[i + 1] = prefixSum[i] + endTime[i] - startTime[i];
    }

    int answer = 0;
    for (int i = k - 1; i < size; i++) {
      int right = i == size - 1 ? eventTime : startTime[i + 1];
      int left = i == k - 1 ? 0 : endTime[i - k];

      int scheduleSum = prefixSum[i + 1] - prefixSum[i - k + 1];

      answer = max(answer, right - left - scheduleSum);
    }
    return answer;
  }
};