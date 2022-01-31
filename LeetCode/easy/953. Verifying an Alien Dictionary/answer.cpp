#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use compare

class Solution {
 private:
  bool isFine(string &a, string &b, vector<int> &orderSet) {
    int length = min(a.length(), b.length());

    bool flag = false;
    for (int i = 0; i < length; i++) {
      if (a[i] == b[i]) continue;
      if (orderSet[a[i] - 'a'] > orderSet[b[i] - 'a']) return false;
      flag = true;
      break;
    }

    if (!flag && a.length() > b.length()) return false;
    return true;
  }

 public:
  bool isAlienSorted(vector<string> &words, string order) {
    vector<int> orderSet('z' - 'a' + 1);
    for (int i = 0; i < order.size(); i++) {
      orderSet[order[i] - 'a'] = i;
    }

    int size = words.size();
    for (int i = 0; i < size - 1; i++) {
      if (!isFine(words[i], words[i + 1], orderSet)) return false;
    }

    return true;
  }
};