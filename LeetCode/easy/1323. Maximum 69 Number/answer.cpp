#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maximum69Number(int num) {
    string numStr = to_string(num);
    string answer = numStr;
    int length = numStr.length();
    for (int i = 0; i < length; i++) {
      string cur = numStr;
      if (cur[i] == '6') {
        cur[i] = '9';
      }

      answer = max(answer, cur);
    }

    return stoi(answer);
  }
};