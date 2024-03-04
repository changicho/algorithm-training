#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy algorithm
// time : O(N)
// space : O(1)
class Solution {
 public:
  string maximumOddBinaryNumber(string s) {
    int size = s.size();
    int oneCount = 0;
    for (char &c : s) {
      if (c == '1') oneCount++;
    }

    s[size - 1] = '1';
    oneCount--;

    for (int i = 0; i < size - 1; i++) {
      if (oneCount > 0) {
        s[i] = '1';
        oneCount--;
      } else {
        s[i] = '0';
      }
    }
    return s;
  }
};