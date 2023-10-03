#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  string reverseWords(string s) {
    string answer = "";
    string temp = "";

    for (char &c : s) {
      if (c == ' ') {
        for (int i = temp.size() - 1; i >= 0; i--) {
          answer += temp[i];
        }
        answer += ' ';
        temp = "";
      } else {
        temp += c;
      }
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
      answer += temp[i];
    }
    return answer;
  }
};

// use one pass (space optimized)
// time : O(N)
// space : O(1)
class Solution {
 public:
  string reverseWords(string s) {
    int size = s.size();
    int left = -1, right = -1;

    for (int i = 0; i < size; i++) {
      if (s[i] == ' ') {
        reverse(s.begin() + left, s.begin() + right + 1);
        left = -1;
        right = -1;
      } else {
        if (left == -1) left = i;
        right = i;
      }
    }
    reverse(s.begin() + left, s.begin() + right + 1);

    return s;
  }
};