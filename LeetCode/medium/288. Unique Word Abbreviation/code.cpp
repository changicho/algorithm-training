#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// use hash map
// time : O(N)
// space : O(N)
class ValidWordAbbr {
 private:
  string convert(string& word) {
    string ret = "";
    int size = word.size();

    ret += word.front();
    if (size - 2 > 0) {
      ret += to_string(size - 2);
    }
    ret += word.back();
    return ret;
  }

  unordered_set<string> origin;
  unordered_map<string, int> um;

 public:
  ValidWordAbbr(vector<string>& dictionary) {
    for (string& d : dictionary) {
      if (origin.count(d) > 0) continue;
      origin.insert(d);
      string c = convert(d);

      um[c]++;
    }
  }

  bool isUnique(string word) {
    string c = convert(word);

    if (um.count(c) == 0) return true;
    if (origin.count(word) && um[c] == 1) return true;
    return false;
  }
};
