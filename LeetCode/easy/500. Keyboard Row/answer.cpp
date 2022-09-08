#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use table
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<string> findWords(vector<string> &words) {
    string lines[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

    int colors[256] = {
        0,
    };
    for (int color = 0; color < 3; color++) {
      for (char c : lines[color]) {
        colors[c] = color;
      }
    }

    vector<string> answer;
    for (string &word : words) {
      set<int> need;

      for (char &c : word) {
        int color = colors[tolower(c)];
        need.insert(color);
      }

      if (need.size() == 1) {
        answer.push_back(word);
      }
    }
    return answer;
  }
};
