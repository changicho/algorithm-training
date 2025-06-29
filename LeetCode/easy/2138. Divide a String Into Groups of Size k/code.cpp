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
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<string> divideString(string s, int k, char fill) {
    int size = s.size();

    vector<string> answer;
    for (int i = 0; i < size; i += k) {
      string cur = "";
      for (int j = 0; j < k; j++) {
        if (i + j >= size) {
          cur += fill;
        } else {
          cur += s[i + j];
        }
      }
      answer.push_back(cur);
    }
    return answer;
  }
};