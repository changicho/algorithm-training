#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// use dynamic programing with BST map

class Solution {
 public:
  int oddEvenJumps(vector<int>& arr) {
    int size = arr.size();

    // dp[index][isOdd]; can reach to last
    vector<vector<bool>> dp(size, vector<bool>(2, false));
    map<int, int> numbers;  // key : num, value : index

    dp[size - 1][true] = true;
    dp[size - 1][false] = true;

    numbers[arr.back()] = size - 1;

    for (int index = size - 2; index >= 0; index--) {
      auto odd = numbers.lower_bound(arr[index]);
      if (odd != numbers.end()) {
        int oddNext = odd->second;
        dp[index][true] = dp[oddNext][false];
      }

      auto even = numbers.upper_bound(arr[index]);
      if (even != numbers.begin()) {
        --even;
        int evenNext = even->second;
        dp[index][false] = dp[evenNext][true];
      }

      numbers[arr[index]] = index;
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
      if (dp[i][true]) answer += 1;
    }

    return answer;
  }
};