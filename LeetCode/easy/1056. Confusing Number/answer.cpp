#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use convert
// time : O(L)
// space : O(L)
class Solution {
 public:
  bool confusingNumber(int n) {
    unordered_map<char, char> table = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    string num = to_string(n);
    string converted = "";

    for (int i = num.length() - 1; i >= 0; i--) {
      if (table.count(num[i]) > 0) {
        converted += table[num[i]];
      } else {
        return false;
      }
    }

    return stoi(converted) != n;
  }
};