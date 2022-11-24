#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use two pointer
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool isStrobogrammatic(string num) {
    unordered_map<char, char> mirror;
    mirror['0'] = '0';
    mirror['1'] = '1';
    mirror['6'] = '9';
    mirror['8'] = '8';
    mirror['9'] = '6';

    int size = num.size();
    for (int left = 0, right = size - 1; left <= right; left++, right--) {
      if (mirror.count(num[left]) == 0 || mirror.count(num[right]) == 0)
        return false;
      if (mirror[num[left]] != num[right]) return false;
    }

    return true;
  }
};