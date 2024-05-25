#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(2^N + N + L)
// space : O(N)
class Solution {
 private:
  int letterCounts[26] = {
      0,
  };
  int answer = 0;

  vector<vector<int>> wordCounts;

  void recursive(int index, int sum, vector<int> &score) {
    if (wordCounts.size() == index) {
      answer = max(answer, sum);
      return;
    }

    recursive(index + 1, sum, score);

    bool isPossible = true;
    int curScore = 0;

    // subtract
    for (int i = 0; i < 26; i++) {
      letterCounts[i] -= wordCounts[index][i];

      curScore += wordCounts[index][i] * score[i];
      if (letterCounts[i] < 0) isPossible = false;
    }

    if (isPossible) recursive(index + 1, sum + curScore, score);

    // rollback
    for (int i = 0; i < 26; i++) {
      letterCounts[i] += wordCounts[index][i];
    }
  }

 public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    int size = words.size();
    for (string &word : words) {
      vector<int> count(26);
      for (char &c : word) {
        count[c - 'a']++;
      }
      wordCounts.push_back(count);
    }

    for (char &c : letters) {
      letterCounts[c - 'a']++;
    }

    recursive(0, 0, score);

    return answer;
  }
};