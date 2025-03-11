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

// use brute force
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int size = arr.size();
    unordered_set<int> us(arr.begin(), arr.end());

    int answer = 0;

    for (int first = 0; first < size; first++) {
      for (int second = first + 1; second < size; second++) {
        int prev = arr[second];
        int target = arr[first] + arr[second];

        int len = 2;

        while (us.count(target) > 0) {
          int temp = target;
          target += prev;
          prev = temp;

          len++;
          answer = max(answer, len);
        }
      }
    }

    return answer;
  }
};

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int size = arr.size();

    vector<vector<int>> dp(size, vector<int>(size, 0));
    int answer = 0;

    for (int cur = 2; cur < size; cur++) {
      int first = 0;
      int second = cur - 1;

      while (first < second) {
        int pairSum = arr[first] + arr[second];

        if (pairSum > arr[cur]) {
          second--;
        } else if (pairSum < arr[cur]) {
          first++;
        } else {
          // pairSum == arr[cur]
          dp[second][cur] = dp[first][second] + 1;

          answer = max(dp[second][cur], answer);
          second--;
          first++;
        }
      }
    }

    return answer == 0 ? 0 : answer + 2;
  }
};