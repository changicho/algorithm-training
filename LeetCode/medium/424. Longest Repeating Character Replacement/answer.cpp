#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(L)
// space : O(1)
class Solution {
 public:
  int characterReplacement(string s, int k) {
    int length = s.length();

    int answer = 0;
    for (char target = 'A'; target <= 'Z'; target++) {
      int diff = 0;
      int left = 0;
      for (int right = 0; right < length; right++) {
        if (s[right] != target) diff++;

        while (diff > k) {
          if (s[left] != target) diff--;
          left++;
        }

        answer = max(answer, right - left + 1);
      }
    }

    return answer;
  }
};