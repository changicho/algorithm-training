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
  int magicalString(int n) {
    string s = "12211";

    int index = 3;
    while (s.length() < n) {
      if (s[index] == '1') {
        if (s.back() == '2') {
          s += "1";
        } else {
          s += "2";
        }
      } else {
        if (s.back() == '2') {
          s += "11";
        } else {
          s += "22";
        }
      }
      index++;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') count++;
    }
    return count;
  }
};