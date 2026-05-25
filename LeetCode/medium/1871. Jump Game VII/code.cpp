#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    int size = s.size();
    vector<bool> visited(size);
    vector<int> prefix(size);
    visited[0] = true;

    for (int i = 0; i < minJump; ++i) {
      prefix[i] = 1;
    }

    for (int i = minJump; i < size; ++i) {
      int left = i - maxJump, right = i - minJump;

      if (s[i] == '0') {
        int total = prefix[right] - (left <= 0 ? 0 : prefix[left - 1]);

        visited[i] = (total != 0);
      }

      prefix[i] = prefix[i - 1] + visited[i];
    }

    return visited[size - 1];
  }
};

// binary search
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    int size = s.size();
    bool answer = false;

    vector<int> zeros;
    for (int i = 1; i < size; i++) {
      if (s[i] == '0') {
        zeros.push_back(i);
      }
    }

    stack<int> stk;
    stk.push(0);
    while (!stk.empty()) {
      int i = stk.top();
      stk.pop();

      if (i == size - 1) return true;

      int left = i + minJump, right = i + maxJump;

      auto l = lower_bound(zeros.begin(), zeros.end(), left) - zeros.begin();
      auto r = upper_bound(zeros.begin(), zeros.end(), right) - zeros.begin();

      for (int j = l; j < r; j++) {
        stk.push(zeros[j]);
      }

      zeros.erase(zeros.begin() + l, zeros.begin() + r);
    }

    return false;
  }
};