#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map

class Solution {
  vector<string> split(string s) {
    stringstream ss(s);

    vector<string> ret;
    string temp;
    while (ss >> temp) {
      ret.emplace_back(temp);
    }
    return ret;
  }

 public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> table;
    unordered_map<string, char> reversed;

    vector<string> words = split(s);

    int length = pattern.length();
    int size = words.size();

    if (size != length) return false;

    for (int i = 0; i < size; i++) {
      char p = pattern[i];
      string word = words[i];

      if (table.find(p) != table.end() && table[p] != word) {
        return false;
      } else {
        table[p] = word;
      }

      if (reversed.find(word) != reversed.end() && reversed[word] != p) {
        return false;
      } else {
        reversed[word] = p;
      }
    }

    return true;
  }
};