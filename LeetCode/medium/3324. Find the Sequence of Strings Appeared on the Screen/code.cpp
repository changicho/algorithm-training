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

// use simulation
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<string> stringSequence(string target) {
    vector<string> answer;

    string cur = "";
    int size = target.size();
    for (int i = 0; i < size; i++) {
      cur += "a";

      for (char c = 'a'; c <= target[i]; c++) {
        cur[i] = c;
        answer.push_back(cur);
      }
    }

    return answer;
  }
};