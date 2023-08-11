#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  string finalString(string s) {
    string ret = "";

    for (char &c : s) {
      if (c == 'i') {
        reverse(ret.begin(), ret.end());
      } else {
        ret += c;
      }
    }

    return ret;
  }
};

// use deque
// time : O(N)
// space : O(N)
class Solution {
 public:
  string finalString(string s) {
    deque<char> dq;
    bool isReversed = false;

    for (char &c : s) {
      if (c == 'i') {
        isReversed = !isReversed;
      } else {
        if (isReversed) {
          dq.push_front(c);
        } else {
          dq.push_back(c);
        }
      }
    }

    string answer =
        isReversed ? string(rbegin(dq), rend(dq)) : string(begin(dq), end(dq));
    return answer;
  }
};