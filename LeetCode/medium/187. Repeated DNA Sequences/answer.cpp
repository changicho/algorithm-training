#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    int length = s.length();
    unordered_set<string> answer_set;
    unordered_set<string> hs;

    for (int index = 0; index < length + 1 - 10; index++) {
      string cur = s.substr(index, 10);

      if (hs.find(cur) != hs.end()) {
        answer_set.insert(cur);
      } else {
        hs.insert(cur);
      }
    }

    vector<string> answers;
    for (string s : answer_set) {
      answers.push_back(s);
    }
    return answers;
  }
};