#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use map sort string to key

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> answer;
    unordered_map<string, vector<string>> m;

    for (string str : strs) {
      string key = str;
      sort(key.begin(), key.end());

      m[key].push_back(str);
    }

    for (auto it : m) {
      answer.push_back(it.second);
    }

    return answer;
  }
};

// use map count string to key

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> answer;
    unordered_map<string, vector<string>> m;

    for (string str : strs) {
      string key = string('z' - 'a' + 1, '0');
      for (char c : str) {
        key[c - 'a'] += 1;
      }

      m[key].push_back(str);
    }

    for (auto it : m) {
      answer.push_back(it.second);
    }

    return answer;
  }
};