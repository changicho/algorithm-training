#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use iteration
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    int size = s.size();

    int before[26] = {
        -1,
    };
    memset(before, -1, sizeof(before));

    int answer = 0;
    for (int i = 0; i < size; i++) {
      if (before[s[i] - 'a'] != -1) {
        int cur = i - before[s[i] - 'a'];
        answer = max(answer, cur);
      } else {
        before[s[i] - 'a'] = i;
      }
    }

    return answer - 1;
  }
};