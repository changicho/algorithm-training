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

// use two pointer

class Solution {
 private:
  bool check(string target, string word) {
    int length1 = target.length(), length2 = word.length();
    int idx2 = 0;

    for (int idx1 = 0; idx1 < length1; idx1++) {
      if (idx2 < length2 && target[idx1] == word[idx2]) {
        idx2++;
      } else if (idx1 > 1 && target[idx1 - 2] == target[idx1 - 1] &&
                 target[idx1 - 1] == target[idx1]) {
      } else if (0 < idx1 && idx1 < length1 - 1 &&
                 target[idx1 - 1] == target[idx1] &&
                 target[idx1] == target[idx1 + 1]) {
      } else {
        return false;
      }
    }

    return idx2 == length2;
  }

 public:
  int expressiveWords(string s, vector<string> &words) {
    int answer = 0;
    for (string &word : words) {
      if (check(s, word)) answer++;
    }

    return answer;
  }
};

// use four pointer

class Solution {
 private:
  bool check(string target, string word) {
    int length1 = target.length(), length2 = word.length();
    int i = 0, j = 0;

    while (i < length1 && j < length2) {
      if (target[i] != word[j]) return false;

      int iNext = i, jNext = j;
      while (iNext < length1 && target[iNext] == target[i]) iNext++;
      while (jNext < length2 && word[jNext] == word[j]) jNext++;

      if (iNext - i != jNext - j && iNext - i < max(3, jNext - j)) return false;

      i = iNext, j = jNext;
    }

    return i == length1 && j == length2;
  }

 public:
  int expressiveWords(string s, vector<string> &words) {
    int answer = 0;
    for (string &word : words) {
      if (check(s, word)) answer++;
    }

    return answer;
  }
};