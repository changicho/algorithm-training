#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int removeAlmostEqualCharacters(string word) {
    int size = word.size();
    vector<vector<int>> dp(101, vector<int>(26, INT_MAX));

    for (int i = 0; i < 26; i++) {
      dp[0][i] = i != word[0] - 'a';
    }

    for (int i = 1; i < size; i++) {
      for (int cur = 0; cur < 26; cur++) {
        for (int before = 0; before < 26; before++) {
          if (abs(cur - before) <= 1) continue;

          dp[i][cur] =
              min(dp[i][cur], dp[i - 1][before] + (cur != word[i] - 'a'));
        }
      }
    }

    int answer = INT_MAX;
    for (int i = 0; i < 26; i++) {
      answer = min(answer, dp[size - 1][i]);
    }
    return answer;
  }
};

// use dynamic programming (space optimized)
// time : O(N)
// space : O(1)
class Solution {
 public:
  int removeAlmostEqualCharacters(string word) {
    int size = word.size();
    vector<int> dp(26, INT_MAX);

    for (int i = 0; i < 26; i++) {
      dp[i] = i != word[0] - 'a';
    }

    for (int i = 1; i < size; i++) {
      vector<int> temp(26, INT_MAX);
      for (int cur = 0; cur < 26; cur++) {
        for (int before = 0; before < 26; before++) {
          if (abs(cur - before) <= 1) continue;

          temp[cur] = min(temp[cur], dp[before] + (cur != word[i] - 'a'));
        }
      }

      dp = temp;
    }

    int answer = INT_MAX;
    for (int i = 0; i < 26; i++) {
      answer = min(answer, dp[i]);
    }
    return answer;
  }
};

// use greedy algorithm
// time : O(N)
// space : O(1)
class Solution {
 public:
  int removeAlmostEqualCharacters(string s) {
    int size = s.size();

    int changed = 0;
    for (int i = 1; i < size; i++) {
      if (abs(s[i] - s[i - 1]) <= 1) {
        changed++;
        i++;
      }
    }

    return changed;
  }
};