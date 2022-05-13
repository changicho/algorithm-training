#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dp
// time : O(N)
// space : O(N)
class Solution {
 private:
  int MOD = 1e9 + 7;

  bool isFourCase(char &key) { return key == '7' || key == '9'; }

 public:
  int countTexts(string pressedKeys) {
    int length = pressedKeys.length();

    vector<int> dpThree = {
        0, 1, 2, 4, 7,
    };
    vector<int> dpFour = {
        0, 1, 2, 4, 8,
    };

    for (int i = 5; i <= length; i++) {
      long long three = 0;
      long long four = 0;

      for (int j = 1; j <= 3; j++) {
        three += dpThree[i - j];
        three %= MOD;
      }

      for (int j = 1; j <= 4; j++) {
        four += dpFour[i - j];
        four %= MOD;
      }

      dpThree.push_back((int)three);
      dpFour.push_back((int)four);
    }

    long long count = 1;
    string before = "";
    for (char &c : pressedKeys) {
      if (c != before.back() && before != "") {
        if (isFourCase(before.back())) {
          count *= (long long)dpFour[before.length()];
        } else {
          count *= (long long)dpThree[before.length()];
        }
        count %= MOD;
        before = "";
      }

      before += c;
    }

    if (isFourCase(before.back())) {
      count *= (long long)dpFour[before.length()];
    } else {
      count *= (long long)dpThree[before.length()];
    }
    count %= MOD;

    return (int)count;
  }
};

// use dp
// time : O(N)
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int countTexts(string pressedKeys) {
    int length = pressedKeys.length();
    vector<long long> dp(length);

    dp[0] = 1;
    for (int i = 1; i < length; i++) {
      char key = pressedKeys[i];
      dp[i] = dp[i - 1];

      for (int before = i - 1; before >= 0 && i - before <= 3; before--) {
        if (key != '7' && key != '9' && i - before == 3) {
          break;
        }
        if (key != pressedKeys[before]) {
          break;
        }
        dp[i] += ((before - 1 >= 0) ? dp[before - 1] : 1);
        dp[i] %= MOD;
      }
    }

    return dp.back();
  }
};