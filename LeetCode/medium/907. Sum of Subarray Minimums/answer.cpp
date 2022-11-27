#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use monotonic stack with dynamic programming
// time : O(N)
// space : O(N)
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
// time : O(N)
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int sumSubarrayMins(vector<int>& arr) {
    int size = arr.size();
    int answer = 0;

    vector<int> leftSizes(size), rightSizes(size);

    stack<pair<int, int>> s1, s2;  // {val, count}

    for (int i = 0; i < size; i++) {
      int count = 1;

      while (!s1.empty() && s1.top().first > arr[i]) {
        count += s1.top().second;
        s1.pop();
      }
      s1.push({arr[i], count});
      leftSizes[i] = count;
    }

    for (int i = size - 1; i >= 0; i--) {
      int count = 1;

      while (!s2.empty() && s2.top().first >= arr[i]) {
        count += s2.top().second;
        s2.pop();
      }
      s2.push({arr[i], count});
      rightSizes[i] = count;
    }

    for (int i = 0; i < size; ++i) {
      answer = (answer + (long)arr[i] * leftSizes[i] * rightSizes[i]) % MOD;
    }
    return answer;
  }
};

// use monotonic stack
// time : O(N)
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int sumSubarrayMins(vector<int>& arr) {
    int size = arr.size();

    stack<int> stk;

    long answer = 0;
    for (int i = 0; i <= size; i++) {
      while (!stk.empty() && (i == size || arr[stk.top()] >= arr[i])) {
        int mid = stk.top();
        stk.pop();

        int left = stk.empty() ? -1 : stk.top();
        int right = i;

        long count = ((mid - left) * (right - mid)) % MOD;

        answer += (count * arr[mid]) % MOD;
        answer %= MOD;
      }

      stk.push(i);
    }

    return answer;
  }
};