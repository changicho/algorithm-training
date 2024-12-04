#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force
// time : O(N + K * M)
// space : O(N)
class Solution {
 private:
  vector<string> split(string &s) {
    stringstream ss(s);
    string temp;
    vector<string> ret;

    while (ss >> temp) {
      ret.push_back(temp);
    }
    return ret;
  }

 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    vector<string> arr = split(sentence);
    int size = arr.size();

    for (int i = 0; i < size; i++) {
      string word = arr[i];
      int idx = word.find(searchWord);

      if (idx == 0) {
        return i + 1;
      }
    }
    return -1;
  }
};