#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use split
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<string> split(string &s) {
    stringstream ss(s);
    string temp;

    vector<string> ret;
    while (ss >> temp) {
      ret.push_back(temp);
    }
    return ret;
  }

 public:
  bool isCircularSentence(string sentence) {
    vector<string> words = split(sentence);

    int size = words.size();
    for (int i = 0; i < size; i++) {
      int next = (i + 1 + size) % size;

      if (words[i].back() != words[next].front()) return false;
    }
    return true;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool isCircularSentence(string sentence) {
    if (sentence.front() != sentence.back()) return false;

    char before;
    bool isNew = false;
    for (char &c : sentence) {
      if (c == ' ') {
        isNew = true;
        continue;
      }

      if (isNew && before != c) return false;
      before = c;
      isNew = false;
    }
    return true;
  }
};