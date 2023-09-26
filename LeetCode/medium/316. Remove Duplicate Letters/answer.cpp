#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use monotonic stack
// time : O(N)
// space : O(1)
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    int size = s.size();

    vector<int> lastIs(26, 0);
    for (int i = 0; i < size; i++) {
      lastIs[s[i] - 'a'] = i;
    }

    vector<bool> visited(26, false);
    stack<char> stk;

    for (int i = 0; i < size; i++) {
      char cur = s[i];
      if (visited[cur - 'a']) {
        continue;
      }
      while (!stk.empty() && stk.top() > s[i] &&
             i < lastIs[stk.top() - 'a']) {
        visited[stk.top() - 'a'] = false;
        stk.pop();
      }
      stk.push(cur);
      visited[cur - 'a'] = true;
    }

    string ans = "";
    while (!stk.empty()) {
      ans += stk.top();
      stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};