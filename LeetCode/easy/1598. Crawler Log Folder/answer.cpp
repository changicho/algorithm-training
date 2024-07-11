#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minOperations(vector<string>& logs) {
    stack<string> stk;

    for (string& log : logs) {
      if (log == "../") {
        if (!stk.empty()) {
          stk.pop();
        }
      } else if (log == "./") {
        continue;
      } else {
        stk.push(log);
      }
    }

    return stk.size();
  }
};

// use count
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minOperations(vector<string>& logs) {
    int count = 0;

    for (string& log : logs) {
      if (log == "../") {
        if (count > 0) {
          count--;
        }
      } else if (log == "./") {
        continue;
      } else {
        count++;
      }
    }

    return count;
  }
};