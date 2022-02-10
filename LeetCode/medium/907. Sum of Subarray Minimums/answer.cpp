#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use monotonic stack with dynamic programming

class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int sumSubarrayMins(vector<int>& arr) {
    int size = arr.size();
    stack<int> minStack;
    // dp[i] : sum of minimum of subarrays end with i (arr[0 ~ i])
    vector<int> dp(size, 0);

    for (int i = 0; i < size; i++) {
      // pop until current index's value is bigest
      while (!minStack.empty() && arr[i] <= arr[minStack.top()]) {
        minStack.pop();
      }

      if (minStack.empty()) {
        dp[i] = ((i + 1) * arr[i]) % MOD;
      } else {
        int prevMinIdx = minStack.top();
        dp[i] = (dp[prevMinIdx] + (i - prevMinIdx) * arr[i]) % MOD;
      }

      minStack.push(i);
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
      answer += dp[i];
      answer %= MOD;
    }

    return answer;
  }
};

// use stack

class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int sumSubarrayMins(vector<int>& arr) {
    int size = arr.size();
    int answer = 0;

    vector<int> left(size), right(size);

    stack<pair<int, int>> s1, s2;  // {val, count}

    for (int i = 0; i < size; i++) {
      int count = 1;

      while (!s1.empty() && s1.top().first > arr[i]) {
        count += s1.top().second;
        s1.pop();
      }
      s1.push({arr[i], count});
      left[i] = count;
    }

    for (int i = size - 1; i >= 0; i--) {
      int count = 1;

      while (!s2.empty() && s2.top().first >= arr[i]) {
        count += s2.top().second;
        s2.pop();
      }
      s2.push({arr[i], count});
      right[i] = count;
    }

    for (int i = 0; i < size; ++i) {
      answer = (answer + (long)arr[i] * left[i] * right[i]) % MOD;
    }
    return answer;
  }
};