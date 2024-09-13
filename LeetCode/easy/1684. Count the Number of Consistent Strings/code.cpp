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

// use one pass
// time : O(N * M)
// space : O(1)
class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    bool check[26] = {false};
    for (char &c : allowed) {
      check[c - 'a'] = true;
    }

    int answer = 0;
    for (string &word : words) {
      bool isFine = true;
      for (char &c : word) {
        if (check[c - 'a'] == false) isFine = false;
      }

      answer += isFine;
    }
    return answer;
  }
};