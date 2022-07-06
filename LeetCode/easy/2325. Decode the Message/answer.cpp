#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  string decodeMessage(string key, string message) {
    char cur = 'a';
    unordered_map<char, char> table;
    for (char &c : key) {
      if (c == ' ') continue;
      if (table.count(c) > 0) continue;

      table[c] = cur;
      cur++;
    }

    table[' '] = ' ';
    string converted = "";
    for (char &c : message) {
      converted += table[c];
    }
    return converted;
  }
};