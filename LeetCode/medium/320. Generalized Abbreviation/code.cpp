#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force
// time : O(2^N)
// space : O(2^N * N)
class Solution {
 private:
  vector<string> answer;

  void recursive(int index, string &word, int temp, string &ret) {
    int size = word.size();
    if (index == size) {
      int beforeLen = ret.size();
      if (temp > 0) ret += to_string(temp);

      answer.push_back(ret);
      while (ret.size() > beforeLen) {
        ret.pop_back();
      }
      return;
    }

    // count case
    recursive(index + 1, word, temp + 1, ret);

    // cut case
    int beforeLen = ret.size();
    if (temp > 0) ret += to_string(temp);

    ret += word[index];
    recursive(index + 1, word, 0, ret);
    while (ret.size() > beforeLen) {
      ret.pop_back();
    }
  }

 public:
  vector<string> generateAbbreviations(string word) {
    string temp = "";
    recursive(0, word, 0, temp);

    return answer;
  }
};