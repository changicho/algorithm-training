#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass

class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int size = values.size();
    int left = 0;
    int answer = values.front() + values.back() + 0 - (size - 1);

    for (int right = 1; right < size; right++) {
      answer = max(answer, values[right] + values[left] + left - right);

      if (values[left] + left < values[right] + right) {
        left = right;
      }
    }

    return answer;
  }
};

// use one pass

class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int answer = 0, before = 0;

    for (int value : values) {
      answer = max(answer, before + value);
      before = max(before, value) - 1;
    }

    return answer;
  }
};

// use dynamic programming

class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int size = values.size();

    vector<int> dp(size, 0);
    dp.front() = values.front() + 0;
    int answer = values.front() + values.back() + 0 - (size - 1);

    for (int i = 1; i < size; i++) {
      answer = max(answer, dp[i - 1] + values[i] - i);
      dp[i] = max(dp[i - 1], values[i] + i);
    }

    return answer;
  }
};