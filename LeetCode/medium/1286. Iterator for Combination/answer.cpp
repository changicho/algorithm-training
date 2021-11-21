#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use make all combination when begin

class CombinationIterator {
 private:
  int index = 0;
  vector<string> combinations;
  string str;

  void recursive(string &cur, int length, int index) {
    if (cur.length() == length) {
      combinations.push_back(cur);

      return;
    }
    if (index == str.length()) {
      return;
    }

    cur += str[index];
    recursive(cur, length, index + 1);
    cur.pop_back();
    recursive(cur, length, index + 1);
  }

 public:
  CombinationIterator(string characters, int combinationLength) {
    str = characters;
    string line = "";
    recursive(line, combinationLength, 0);
  }

  string next() {
    string ret = combinations[index];
    index++;
    return ret;
  }

  bool hasNext() { return index != combinations.size(); }
};

// use bitmask

class CombinationIterator {
  string s;
  int n, length, mask = 0;
  bool has_next = true;

 public:
  CombinationIterator(string s, int n) {
    this->s = s;
    this->n = n;
    this->length = s.length();
    mask = (1 << n) - 1 << (length - n);
  }

  string next() {
    string combination = "";
    for (int index = length - 1; index >= 0; index--) {
      if (mask & 1 << index) {
        combination += s[length - 1 - index];
      }
    }
    updateMask();
    return combination;
  }
  // using Gospel's hack
  void updateMask() {
    int t = mask + 1, u = t ^ mask, v = t & mask;

    mask = v - (v & -v) / (u + 1);
    has_next = mask != 0;
  }

  bool hasNext() { return has_next; }
};