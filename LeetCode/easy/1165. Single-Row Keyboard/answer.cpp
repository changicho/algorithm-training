#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use table
// time : O(N)
// space : O(1)
class Solution {
 public:
  int calculateTime(string keyboard, string word) {
    int indexes[26] = {
        0,
    };
    for (int i = 0; i < 26; i++) {
      char cur = keyboard[i];

      indexes[cur - 'a'] = i;
    }

    int answer = 0;
    int before = 0;
    for (char &c : word) {
      answer += abs(before - indexes[c - 'a']);
      before = indexes[c - 'a'];
    }
    return answer;
  }
};