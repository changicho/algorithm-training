#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy algorithm
// time : O(N * (L + log_2(N)))
// space : O(N)
class Solution {
 public:
  int maxPalindromesAfterOperations(vector<string> &words) {
    int counts[26] = {
        0,
    };
    int pairs = 0;
    int answer = 0;

    vector<int> lengths;
    for (string &w : words) {
      for (char &c : w) {
        counts[c - 'a']++;
      }

      lengths.push_back(w.size());
    }

    for (int i = 0; i < 26; i++) {
      pairs += counts[i] / 2;
    }

    sort(lengths.begin(), lengths.end());
    for (int &length : lengths) {
      pairs -= length / 2;

      if (pairs >= 0) {
        answer++;
      }
    }
    return answer;
  }
};