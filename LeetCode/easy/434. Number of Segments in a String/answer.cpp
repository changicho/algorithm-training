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
  int countSegments(string s) {
    string temp = "";
    int answer = 0;
    for (char &c : s) {
      if (c == ' ') {
        if (temp.length() > 0) answer++;
        temp = "";
        continue;
      }
      temp += c;
    }
    if (temp.length() > 0) answer++;

    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int countSegments(string s) {
    int tempLength = 0;
    int answer = 0;
    for (char &c : s) {
      if (c == ' ') {
        if (tempLength > 0) answer++;
        tempLength = 0;
        continue;
      }
      tempLength++;
    }
    if (tempLength > 0) answer++;

    return answer;
  }
};

// use stringstream
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countSegments(string s) {
    stringstream ss(s);
    int answer = 0;
    while (ss >> s) answer++;
    return answer;
  }
};
