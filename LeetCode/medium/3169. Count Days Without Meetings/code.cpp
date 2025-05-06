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

// use BST map
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int countDays(int days, vector<vector<int>> &meetings) {
    map<int, int> m;
    for (vector<int> &meeting : meetings) {
      int left = meeting[0], right = meeting[1];
      m[left] = max(m[left], right);
    }

    int answer = 0;
    int before = 1;
    for (auto &[left, right] : m) {
      if (before < left) {
        answer += left - before;
      }
      before = max(before, right + 1);
    }
    if (before <= days) {
      answer += days - before + 1;
    }

    return answer;
  }
};