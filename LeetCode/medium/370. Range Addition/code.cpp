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

// use diff array
// time : O(N + Q)
// space : O(N)
class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> answer(length + 1, 0);

    for (vector<int>& u : updates) {
      int left = u[0], right = u[1], diff = u[2];

      answer[left] += diff;
      answer[right + 1] -= diff;
    }

    // remove the extra element
    answer.pop_back();
    int cur = 0;
    for (int i = 0; i < length; i++) {
      cur += answer[i];

      answer[i] = cur;
    }
    return answer;
  }
};