#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use count
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minSteps(string s, string t) {
    int count1[26] =
        {
            0,
        },
        count2[26] = {
            0,
        };

    for (char &c : s) {
      count1[c - 'a']++;
    }
    for (char &c : t) {
      count2[c - 'a']++;
    }

    int answer = 0;
    for (int i = 0; i < 26; i++) {
      if (count2[i] != count1[i]) {
        answer += abs(count2[i] - count1[i]);
      }
    }
    return answer / 2;
  }
};