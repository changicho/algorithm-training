#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use combination

class Solution {
 public:
  int memo[34][34];
  vector<int> getRow(int rowIndex) {
    vector<int> answer;

    for (int i = 0; i <= rowIndex; i++) {
      answer.push_back(combination(rowIndex, i));
    }

    return answer;
  }

  int combination(int n, int c) {
    if (memo[n][c] != 0) return memo[n][c];
    if (n == c || c == 0) {
      memo[n][c] = 1;
      return 1;
    }
    if (c == 1) {
      memo[n][c] = n;
      return n;
    }
    memo[n][c] = combination(n - 1, c) + combination(n - 1, c - 1);
    return memo[n][c];
  }
};

// use only one row

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res;

    long c = 1;
    for (int i = 1; i <= rowIndex + 1; i++) {
      res.push_back(c);
      c = c * (rowIndex + 1 - i) / i;
    }
    return res;
  }
};