#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use max length of substring end char
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool isNext(char &from, char &to) {
    if (from == 'z' && to == 'a') return true;
    return to - from == 1;
  }

 public:
  int findSubstringInWraproundString(string p) {
    int length = p.length();
    string temp = "";

    vector<int> maxLengths(26, 0);
    for (int i = 0; i < length; i++) {
      if (!temp.empty() && isNext(temp.back(), p[i])) {
        temp += p[i];
      } else {
        temp = "";
        temp += p[i];
      }

      int curLength = temp.length();
      maxLengths[temp.back() - 'a'] =
          max(curLength, maxLengths[temp.back() - 'a']);
    }

    int answer = 0;
    for (int &length : maxLengths) {
      answer += length;
    }

    return answer;
  }
};

// use max length of substring end char
// time : O(N)
// space : O(1)
class Solution {
 private:
  bool isNext(char &from, char &to) {
    if (from == 'z' && to == 'a') return true;
    return to - from == 1;
  }

 public:
  int findSubstringInWraproundString(string p) {
    int length = p.length();

    int tempLength = 0;
    vector<int> maxLengths(26, 0);
    for (int i = 0; i < length; i++) {
      if (tempLength == 0 || !isNext(p[i - 1], p[i])) {
        tempLength = 0;
      }
      tempLength++;
      maxLengths[p[i] - 'a'] = max(tempLength, maxLengths[p[i] - 'a']);
    }

    int answer = 0;
    for (int &length : maxLengths) {
      answer += length;
    }

    return answer;
  }
};