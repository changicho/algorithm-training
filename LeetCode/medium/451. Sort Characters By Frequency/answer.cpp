#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use custom sort
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Char {
    char key;
    int count;

    bool operator<(const Char &b) const {
      if (count != b.count) return count > b.count;
      return key < b.key;
    }
  };

 public:
  string frequencySort(string s) {
    unordered_map<char, int> counts;

    for (char &c : s) {
      counts[c]++;
    }

    vector<Char> chars;
    for (auto &it : counts) {
      char key = it.first;
      int count = it.second;

      chars.push_back({key, count});
    }

    sort(chars.begin(), chars.end());

    string ret = "";
    for (Char &cur : chars) {
      ret += string(cur.count, cur.key);
    }
    return ret;
  }
};