#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use dp with left, right index

class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    int length = input.length();
    return computeWithDP(input, 0, length - 1);
  }

 private:
  vector<int> dp[21][21];
  vector<int> computeWithDP(string &line, int left, int right) {
    if (left == right) {
      return dp[left][right] = {line[left] - '0'};
    }

    vector<int> result;

    for (int i = left; i <= right; i++) {
      if (isdigit(line[i])) continue;
      char oper = line[i];

      if (left <= i - 1 && dp[left][i].empty()) {
        dp[left][i - 1] = computeWithDP(line, left, i - 1);
      }

      if (i + 1 <= right && dp[i + 1][right].empty()) {
        dp[i + 1][right] = computeWithDP(line, i + 1, right);
      }

      for (int leftVal : dp[left][i - 1]) {
        for (int rightVal : dp[i + 1][right]) {
          result.push_back(operation(leftVal, rightVal, oper));
        }
      }
    }

    if (result.empty()) {
      result.push_back(stoi(line.substr(left, right - left + 1)));
    }

    dp[left][right] = result;
    return result;
  }

  int operation(int left, int right, char oper) {
    if (oper == '+')
      return (left + right);
    else if (oper == '-')
      return (left - right);
    else
      return (left * right);
  }
};

// use dp with substr

class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    unordered_map<string, vector<int>> dp;

    return computeWithDP(input, dp);
  }

 private:
  vector<int> computeWithDP(string line, unordered_map<string, vector<int>> &dp) {
    vector<int> result;
    int length = line.length();

    for (int i = 0; i < length; i++) {
      char oper = line[i];

      if (isdigit(oper)) continue;

      vector<int> leftVector, rightVector;
      string leftKey = line.substr(0, i);

      if (dp.find(leftKey) != dp.end()) {
        leftVector = dp[leftKey];
      } else {
        leftVector = computeWithDP(leftKey, dp);
      }

      string rightKey = line.substr(i + 1);
      if (dp.find(rightKey) != dp.end()) {
        rightVector = dp[rightKey];
      } else {
        rightVector = computeWithDP(rightKey, dp);
      }

      for (int left : leftVector) {
        for (int right : rightVector) {
          result.push_back(operation(left, right, oper));
        }
      }
    }

    if (result.empty()) {
      result.push_back(stoi(line));
    }

    dp[line] = result;
    return result;
  }

  int operation(int left, int right, char oper) {
    if (oper == '+')
      return (left + right);
    else if (oper == '-')
      return (left - right);
    else
      return (left * right);
  }
};