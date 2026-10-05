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

// stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  int scoreOfParentheses(string s) {
    stack<int> stk;

    int temp = 0;
    for (char& c : s) {
      if (c == '(') {
        stk.push(temp);

        temp = 0;
      } else {
        int before = temp == 0 ? 1 : temp * 2;
        temp = stk.top() + before;
        stk.pop();
      }
    }
    return temp;
  }
};

// depth count
// time : O(N)
// space : O(1)
class Solution {
 public:
  int scoreOfParentheses(string s) {
    int size = s.size();
    int depth = 1;
    int answer = 0;
    for (int i = 0; i < size; i++) {
      char& c = s[i];
      if (c == '(') {
        depth *= 2;
      } else {
        depth /= 2;
        if (s[i - 1] == '(') {
          answer += depth;
        }
      }
    }
    return answer;
  }
};