#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force
// time : O(2^L * L + N)
// space : O(N)
class Solution {
 private:
  string convert(vector<string> &words) {
    string ret = "";
    for (string &w : words) {
      ret += w + " ";
    }
    ret.pop_back();
    return ret;
  }

 public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> us(wordDict.begin(), wordDict.end());

    vector<string> answer;

    vector<string> temp;
    function<void(int)> recursive = [&](int index) {
      int size = s.size();
      if (size == index) {
        answer.push_back(convert(temp));
        return;
      }

      string key = "";
      for (int i = index; i < size; i++) {
        key += s[i];

        if (us.count(key) == 0) continue;

        temp.push_back(key);
        recursive(i + 1);
        temp.pop_back();
      }
    };

    recursive(0);

    return answer;
  }
};