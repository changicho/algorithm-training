#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(N)

class Solution {
 public:
  string getHint(string secret, string guess) {
    int bulls = 0;
    int cows = 0;

    int length = secret.length();
    vector<bool> visitedSecret(length, false);
    vector<bool> visitedGuess(length, false);

    for (int target = 0; target < length; target++) {
      if (secret[target] == guess[target]) {
        visitedSecret[target] = visitedGuess[target] = true;
        bulls += 1;
      }
    }

    for (int target = 0; target < length; target++) {
      if (visitedSecret[target]) continue;

      for (int cur = 0; cur < length; cur++) {
        if (visitedGuess[cur]) continue;

        if (secret[target] == guess[cur]) {
          cows += 1;

          visitedGuess[cur] = visitedSecret[target] = true;

          break;
        }
      }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};

// use hash map
// time : O(N)
// space : O(10)

class Solution {
 public:
  string getHint(string secret, string guess) {
    int bulls = 0;
    int cows = 0;

    int length = secret.length();
    unordered_map<char, int> secretMap;
    unordered_map<char, int> guessMap;

    for (int index = 0; index < length; index++) {
      if (secret[index] == guess[index]) {
        bulls += 1;
      } else {
        secretMap[secret[index]] += 1;
        guessMap[guess[index]] += 1;
      }
    }

    for (auto &cur : secretMap) {
      cows += min(cur.second, guessMap[cur.first]);
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};