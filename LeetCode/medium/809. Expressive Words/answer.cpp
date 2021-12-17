#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use converting

class Solution {
 private:
  struct Data {
    char c;
    int count;
  };

  vector<Data> convertString(string &str) {
    char before = str.front();
    int count = 1;

    vector<Data> ret;

    for (int i = 1; i < str.length(); i++) {
      if (before != str[i]) {
        ret.push_back({before, count});

        before = str[i];
        count = 1;
        continue;
      }
      count++;
    }
    ret.push_back({before, count});

    return ret;
  }

  bool canStretch(string &from, vector<Data> &targets) {
    vector<Data> froms = convertString(from);

    if (froms.size() != targets.size()) return false;

    int size = froms.size();
    for (int i = 0; i < size; i++) {
      if (froms[i].c != targets[i].c) return false;
      if (froms[i].count > targets[i].count) return false;
      if (froms[i].count != 2 && targets[i].count == 2) return false;
    }
    return true;
  }

 public:
  int expressiveWords(string s, vector<string> &words) {
    vector<Data> targets = convertString(s);

    int answer = 0;
    for (string &word : words) {
      if (canStretch(word, targets)) answer++;
    }
    return answer;
  }
};