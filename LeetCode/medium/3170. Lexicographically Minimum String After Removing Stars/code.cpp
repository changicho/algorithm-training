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

// use greedy
// time : O(N)
// space : O(N)
class Solution {
 public:
  string clearStars(string s) {
    int size = s.size();

    vector<bool> deleted(size, false);
    vector<stack<int>> indexes(26);

    for (int i = 0; i < size; i++) {
      if (s[i] == '*') {
        int target = -1;
        for (int c = 0; c < 26; c++) {
          if (indexes[c].empty()) continue;

          target = indexes[c].top();
          indexes[c].pop();
          break;
        }

        if (target != -1) {
          deleted[target] = true;
        }

      } else {
        indexes[s[i] - 'a'].push(i);
      }
    }

    string answer = "";
    for (int i = 0; i < size; i++) {
      if (deleted[i] || s[i] == '*') continue;
      answer += s[i];
    }
    return answer;
  }
};