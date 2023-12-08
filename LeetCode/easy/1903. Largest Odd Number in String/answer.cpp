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
  string largestOddNumber(string num) {
    int size = num.size();

    int lastI = -1;
    for (int i = 0; i < size; i++) {
      char c = num[i];
      int digit = c - '0';

      if (digit % 2 == 1) {
        lastI = i;
      }
    }
    string answer = num.substr(0, lastI + 1);
    return answer;
  }
};