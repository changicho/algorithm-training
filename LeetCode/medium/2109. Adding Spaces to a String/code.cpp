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

// use two pointer
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  string addSpaces(string s, vector<int>& spaces) {
    int size = s.size();
    string ret = "";

    for (int i = 0, sI = 0; i < size; i++) {
      if (sI < spaces.size() && spaces[sI] == i) {
        ret += ' ';
        sI++;
      }
      ret += s[i];
    }

    return ret;
  }
};