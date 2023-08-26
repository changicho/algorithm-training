#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use DFS dynamic programming
// time : O(N * M)
// space : O(N * M)
class Solution {
 public:
  bool visited[100][100] = {
      false,
  };
  bool dp[100][100] = {
      false,
  };
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) return false;

    return recursive(s1, s2, s3, 0, 0, 0);
  }

  bool recursive(string &s1, string &s2, string &s3, int idx1, int idx2,
                 int idx3) {
    if (idx3 == s3.length()) return true;
    if (visited[idx1][idx2] == true) return dp[idx1][idx2];

    bool response = false;
    if (idx1 < s1.length() && s3[idx3] == s1[idx1]) {
      response |= recursive(s1, s2, s3, idx1 + 1, idx2, idx3 + 1);
    }
    if (idx2 < s2.length() && s3[idx3] == s2[idx2]) {
      response |= recursive(s1, s2, s3, idx1, idx2 + 1, idx3 + 1);
    }

    visited[idx1][idx2] = true;
    return dp[idx1][idx2] = response;
  }
};

// use BFS dynamic programming
// time : O(N * M)
// space : O(N * M)
class Solution {
 private:
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();

    if (size1 + size2 != size3) return false;

    bool dp[101][101] = {
        false,
    };

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      if (dp[cur.first][cur.second]) continue;
      dp[cur.first][cur.second] = true;

      if (cur.first == size1 && cur.second == size2) break;

      int target = cur.first + cur.second;

      if (cur.first < size1 && s3[target] == s1[cur.first]) {
        q.push({cur.first + 1, cur.second});
      }
      if (cur.second < size2 && s3[target] == s2[cur.second]) {
        q.push({cur.first, cur.second + 1});
      }
    }

    return dp[size1][size2];
  }
};

// use iterative dynamic programming
// time : O(N * M)
// space : O(N * M)
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
    if (size1 + size2 != size3) return false;

    bool dp[101][101] = {
        false,
    };

    for (int i = 0; i <= size1; i++) {
      for (int j = 0; j <= size2; j++) {
        int target = i + j - 1;

        if (i == 0 && j == 0) {
          dp[i][j] = true;
        } else if (i == 0) {
          dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[target]);
        } else if (j == 0) {
          dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[target]);
        } else {
          dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[target]) ||
                     (dp[i][j - 1] && s2[j - 1] == s3[target]);
        }
      }
    }

    return dp[size1][size2];
  }
};

// use dynamic programming (space optimized)
// time : O(N * M)
// space : O(N)
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
    if (size1 + size2 != size3) return false;

    bool dp[102] = {
        false,
    };
    dp[0] = true;

    for (int j = 1; j <= size2; ++j) {
      dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
    }

    for (int i = 1; i <= size1; i++) {
      dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
      for (int j = 1; j <= size2; j++) {
        dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
      }
    }

    return dp[size2];
  }
};