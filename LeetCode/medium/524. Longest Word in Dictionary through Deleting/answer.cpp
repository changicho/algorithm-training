#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use index binary search
// time : O(L + N * M * log_2(L))
// space : O(L + M)
class Solution {
 public:
  string findLongestWord(string s, vector<string> &dictionary) {
    vector<int> indexes[26];

    for (int i = 0; i < s.size(); i++) {
      indexes[s[i] - 'a'].push_back(i);
    }

    string answer = "";
    for (string &word : dictionary) {
      int index = -1;
      bool isError = false;
      for (char &c : word) {
        if (indexes[c - 'a'].empty() || indexes[c - 'a'].back() <= index) {
          isError = true;
          break;
        }

        int nextIdx = upper_bound(indexes[c - 'a'].begin(),
                                  indexes[c - 'a'].end(), index) -
                      indexes[c - 'a'].begin();
        index = indexes[c - 'a'][nextIdx];
      }

      if (isError) continue;
      if (answer == "") {
        answer = word;
      } else if (answer.size() < word.size()) {
        answer = word;
      } else if (answer.size() == word.size() && answer > word) {
        answer = word;
      }
    }
    return answer;
  }
};