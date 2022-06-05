#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(1)
// space : O(1)
class Solution {
 public:
  bool digitCount(string num) {
    vector<int> counts(10);
    for (char &n : num) {
      counts[n - '0']++;
    }

    string converted = "";
    for (int i = 0; i < 10; i++) {
      converted += to_string(counts[i]);
    }

    while (num.length() < 10) {
      num += '0';
    }

    return converted == num;
  }
};