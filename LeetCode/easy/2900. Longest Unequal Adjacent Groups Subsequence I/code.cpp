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
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<string> getLongestSubsequence(vector<string>& words,
                                       vector<int>& groups) {
    int size = words.size();

    vector<string> answer;

    int beforeG = -1;
    for (int i = 0; i < size; i++) {
      if (beforeG != groups[i]) {
        answer.push_back(words[i]);
        beforeG = groups[i];
      } else {
        continue;
      }
    }
    return answer;
  }
};