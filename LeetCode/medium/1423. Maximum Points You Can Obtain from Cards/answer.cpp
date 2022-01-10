#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programing

class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int size = cardPoints.size();
    vector<int> dp(size + 1, 0);

    dp[1] = cardPoints[0];
    for (int i = 2; i <= size; i++) {
      dp[i] = dp[i - 1] + cardPoints[i - 1];
    }

    int answer = dp[k - 1];
    int diff = size - k - 1;
    for (int left = 0; left <= k; left++) {
      int leftPart = dp[left];
      int rightPart = dp[size] - dp[size - (k - left)];

      int curAnswer = leftPart + rightPart;
      answer = max(curAnswer, answer);
    }

    return answer;
  }
};

// use two pointer

class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int size = cardPoints.size();

    int curSum = 0;
    for (int i = 0; i < k; i++) {
      curSum += cardPoints[i];
    }
    int answer = curSum;

    for (int left = k - 1; left >= 0; left--) {
      int right = left + size - k;

      curSum -= cardPoints[left];
      curSum += cardPoints[right];

      answer = max(curSum, answer);
    }

    return answer;
  }
};