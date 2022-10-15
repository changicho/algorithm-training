#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use stack & count
// time : O(N)
// space : O(N)
class Solution {
 public:
  string robotWithString(string s) {
    string answer;
    stack<char> t;

    map<char, int> count;
    for (char &c : s) {
      count[c]++;
    }

    for (char &c : s) {
      t.push(c);
      count[c]--;
      if (count[c] == 0) {
        count.erase(c);
      }

      char lowest = count.empty() ? 'z' : count.begin()->first;
      while (!t.empty() && t.top() <= lowest) {
        answer += t.top();
        t.pop();
      }
    }
    return answer;
  }
};