#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    int size = preorder.size();
    if (size <= 1) return true;

    stack<int> s;
    s.push(preorder.front());
    int beforeLeft = -1;

    for (int i = 1; i < size; i++) {
      if (s.empty() || preorder[i] < s.top()) {
        if (preorder[i] < beforeLeft) return false;

        s.push(preorder[i]);
      } else {
        while (!s.empty() && s.top() < preorder[i]) {
          beforeLeft = s.top();
          s.pop();
        }
        s.push(preorder[i]);
      }
    }
    return true;
  }
};