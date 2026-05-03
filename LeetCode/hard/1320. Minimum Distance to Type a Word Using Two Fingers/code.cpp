#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 private:
  int getDist(int a, int b) {
    int ay = a / 6, ax = a % 6;
    int by = b / 6, bx = b % 6;

    return abs(ay - by) + abs(ax - bx);
  }

 public:
  int minimumDistance(string word) {
    int size = word.size();

    // [index][first][second]
    vector<vector<vector<int>>> dp(
        size + 1, vector<vector<int>>(26, vector<int>(26, INT_MAX)));

    for (int i = 0; i < 26 * 26; i++) {
      int c = word[0] - 'A';
      int first = i / 26;
      int second = i % 26;

      if (first == c || second == c) {
        dp[0][first][second] = 0;
      }
    }

    for (int i = 1; i < size; i++) {
      int c = word[i] - 'A';

      for (int before = 0; before < 26 * 26; before++) {
        int first = before / 26, second = before % 26;
        if (dp[i - 1][first][second] == INT_MAX) continue;

        // move first
        int diffFirst = getDist(c, first);

        dp[i][c][second] =
            min(dp[i][c][second], dp[i - 1][first][second] + diffFirst);

        // move second
        int diffSecond = getDist(c, second);
        dp[i][first][c] =
            min(dp[i][first][c], dp[i - 1][first][second] + diffSecond);
      }
    }

    int answer = INT_MAX;
    for (int i = 0; i < 26 * 26; i++) {
      int c = word[0] - 'A';
      int first = i / 26;
      int second = i % 26;

      answer = min(answer, dp[size - 1][first][second]);
    }
    return answer;
  }
};

// dynamic programming (space optimize)
// time : O(N)
// space : O(1)
class Solution {
 private:
  int getDist(int a, int b) {
    int ay = a / 6, ax = a % 6;
    int by = b / 6, bx = b % 6;

    return abs(ay - by) + abs(ax - bx);
  }

 public:
  int minimumDistance(string word) {
    int size = word.size();

    // [first * 26 + second]
    vector<int> dp(26 * 26, INT_MAX);

    for (int i = 0; i < 26 * 26; i++) {
      int c = word[0] - 'A';
      int first = i / 26;
      int second = i % 26;

      if (first == c || second == c) {
        dp[i] = 0;
      }
    }

    for (int i = 1; i < size; i++) {
      vector<int> temp(26 * 26, INT_MAX);

      int c = word[i] - 'A';

      for (int before = 0; before < 26 * 26; before++) {
        int first = before / 26, second = before % 26;
        if (dp[before] == INT_MAX) continue;

        // move first
        int diffFirst = getDist(c, first);

        temp[c * 26 + second] =
            min(temp[c * 26 + second], dp[before] + diffFirst);

        // move second
        int diffSecond = getDist(c, second);
        temp[first * 26 + c] =
            min(temp[first * 26 + c], dp[before] + diffSecond);
      }
      dp = temp;
    }

    int answer = INT_MAX;
    for (int i = 0; i < 26 * 26; i++) {
      int c = word[0] - 'A';
      int first = i / 26;
      int second = i % 26;

      answer = min(answer, dp[first * 26 + second]);
    }
    return answer;
  }
};