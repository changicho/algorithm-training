#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  vector<string> split(string &s) {
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
    vector<string> tokens = split(s);

    if (pattern.size() != tokens.size()) return false;
    unordered_map<char, string> patternToWord;
    unordered_map<string, char> wordToPattern;

    for (int i = 0; i < pattern.size(); i++) {
      char key = pattern[i];
      string val = tokens[i];

      if (patternToWord.count(key) == 0 && wordToPattern.count(val) == 0) {
        patternToWord[key] = val;
        wordToPattern[val] = key;
      } else if (patternToWord[key] == val && wordToPattern[val] == key) {
        continue;
      } else {
        return false;
      }
    }
    return true;
  }
};

// use hash map (convert)
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  vector<string> split(string &s) {
    stringstream ss(s);

    vector<string> ret;
    string temp;
    while (ss >> temp) {
      ret.emplace_back(temp);
    }
    return ret;
  }

  string convert(vector<string> &words) {
    unordered_map<string, int> um;

    string ret = "";
    for (string &word : words) {
      if (um.count(word) == 0) {
        um[word] = um.size();
      }
      ret += to_string(um[word]);
    }

    return ret;
  }

 public:
  bool wordPattern(string pattern, string s) {
    vector<string> first = split(s);
    vector<string> second;

    for (char &c : pattern) {
      second.push_back({c});
    }

    return convert(second) == convert(first);
  }
};