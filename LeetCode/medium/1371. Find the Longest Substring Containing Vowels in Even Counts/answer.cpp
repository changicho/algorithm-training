#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use status bitmask
// time : O(N)
// space : O(N)
class Solution {
 private:
  int convert(char c) {
    switch (c) {
      case 'a':
        return 0;
      case 'e':
        return 1;
      case 'i':
        return 2;
      case 'o':
        return 3;
      case 'u':
        return 4;
    }
    return -1;
  }

 public:
  int findTheLongestSubstring(string s) {
    int size = s.size();

    unordered_map<int, int> beforeIs;
    int bit = 0;
    beforeIs[0] = -1;

    int answer = 0;
    for (int i = 0; i < size; i++) {
      int cur = convert(s[i]);
      if (cur != -1) {
        bit ^= (1 << cur);
      }

      if (beforeIs.count(bit) == 0) {
        beforeIs[bit] = i;
      } else {
        answer = max(answer, i - (beforeIs[bit] + 1) + 1);
      }
    }
    return answer;
  }
};