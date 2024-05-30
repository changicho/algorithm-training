#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(N^2)
// space : O(1)
class Solution {
 private:
  string addOne(string &s) {
    reverse(s.begin(), s.end());

    int carry = 1;
    for (int i = 0; i < s.size(); i++) {
      s[i] += carry;
      if (s[i] >= '2') {
        carry = 1;
        s[i] = '0';
      } else {
        carry = 0;
      }
    }

    if (carry) {
      s.push_back('1');
    }
    reverse(s.begin(), s.end());
    return s;
  }

 public:
  int numSteps(string s) {
    int answer = 0;
    while (s != "1") {
      answer++;
      if (s.back() == '1') {
        s = addOne(s);
      } else {
        s.pop_back();
      }
    }
    return answer;
  }
};

// use greedy
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numSteps(string s) {
    int size = s.size();

    int answer = 0;
    int carry = 0;

    for (int i = size - 1; i > 0; i--) {
      answer++;

      if ((s[i] - '0' + carry) % 2 == 1) {
        answer++;
      }

      // update carry
      if (s[i] - '0' + carry > 0) {
        carry = 1;
      } else {
        carry = 0;
      }
    }

    return answer + carry;
  }
};