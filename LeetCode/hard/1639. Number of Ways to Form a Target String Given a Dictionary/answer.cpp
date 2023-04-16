#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming & prefix sum
// time : O(L * (N + M))
// space : O(L * M)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int numWays(vector<string>& words, string target) {
    int size = words.size();
    int wordLength = words[0].size();
    int length = target.size();

    int counts[1001][26] = {
        0,
    };
    for (int i = 0; i < wordLength; i++) {
      for (int j = 0; j < size; j++) {
        counts[i][words[j][i] - 'a']++;
      }
    }

    long dp[1001][1001] = {
        0,
    };  // index, length;
    long prefixes[1001] = {
        0,
    };  // length

    for (int i = 0; i < wordLength; i++) {
      char curChar = target[0];
      dp[i][0] = counts[i][curChar - 'a'];
    }

    for (int len = 0; len < length; len++) {
      prefixes[0] += dp[0][len];
    }

    for (int i = 1; i < wordLength; i++) {
      for (int len = 1; len < length; len++) {
        char curChar = target[len];

        // for(int before = 0; before < i; before++){
        //     dp[i][len] += dp[before][len-1] * counts[i][curChar - 'a'];
        //     dp[i][len] %= MOD;
        // }
        dp[i][len] += prefixes[len - 1] * counts[i][curChar - 'a'];
        dp[i][len] %= MOD;
      }

      // prefix update
      for (int len = 0; len < length; len++) {
        prefixes[len] = prefixes[len] + dp[i][len];
        prefixes[len] %= MOD;
      }
    }

    int answer = 0;
    for (int i = 0; i < wordLength; i++) {
      answer += dp[i][length - 1];
      answer %= MOD;
    }

    return answer;
  }
};

// use dynamic programming & prefix sum (space optimization)
// time : O(L * (N + M))
// space : O(L)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int numWays(vector<string>& words, string target) {
    int size = words.size();
    int wordLength = words[0].size();
    int length = target.size();

    int counts[1001][26] = {
        0,
    };
    for (int i = 0; i < wordLength; i++) {
      for (int j = 0; j < size; j++) {
        counts[i][words[j][i] - 'a']++;
      }
    }

    long dp[1001] = {
        0,
    };  // length;
    long prefixes[1001] = {
        0,
    };  // length

    int answer = 0;
    for (int i = 0; i < wordLength; i++) {
      for (int len = 0; len < length; len++) {
        char curChar = target[len];

        dp[len] = ((len - 1) < 0)
                      ? counts[i][curChar - 'a']
                      : prefixes[len - 1] * counts[i][curChar - 'a'];
        dp[len] %= MOD;

        if (len == length - 1) {
          answer += dp[len];
          answer %= MOD;
        }
      }

      // prefix update
      for (int len = 0; len < length; len++) {
        prefixes[len] = prefixes[len] + dp[len];
        prefixes[len] %= MOD;
      }
    }

    return answer;
  }
};