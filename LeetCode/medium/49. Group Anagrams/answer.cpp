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

// use counting sort
// N : str.size, L : word.length
// time : O(N * L)
// space : O(N * L)
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // space : O(N * L)
    unordered_map<string, vector<string>> groups;

    // O(N)
    for (string& str : strs) {
      vector<int> charCount('z' - 'a' + 1, 0);
      for (char& c : str) {
        charCount[c - 'a']++;
      }

      string key = "";
      // O(26)
      for (int& c : charCount) {
        key += "#" + to_string(c);
      }

      groups[key].push_back(str);
    }

    // O(N * L)
    vector<vector<string>> answer;
    for (auto it : groups) {
      answer.push_back(it.second);
    }
    return answer;
  }
};