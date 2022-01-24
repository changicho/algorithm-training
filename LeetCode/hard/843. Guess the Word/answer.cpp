#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master {
 public:
  int guess(string word);
};

// use backtracking

class Solution {
 private:
  int getMatches(string& a, string& b) {
    int matches = 0;
    int length = min(a.length(), b.length());

    for (int i = 0; i < length; ++i) {
      if (a[i] == b[i]) matches++;
    }
    return matches;
  }

 public:
  void findSecretWord(vector<string>& wordlist, Master& master) {
    // shuffle wordList by random
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(wordlist.begin(), wordlist.end(), default_random_engine(seed));

    for (int tried = 0, matches = 0; tried < 10 && matches < 6; ++tried) {
      string guess = wordlist.front();
      matches = master.guess(guess);

      vector<string> newWordList;

      // only pick match with current word
      for (string& w : wordlist) {
        if (getMatches(guess, w) == matches) {
          newWordList.push_back(w);
        }
      }
      wordlist = newWordList;
    }
  }
};