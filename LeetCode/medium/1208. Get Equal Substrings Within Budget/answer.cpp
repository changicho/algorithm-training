#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  int equalSubstring(string s, string t, int maxCost) {
    int size = s.size();

    int temp = maxCost;
    int answer = 0;

    for (int left = 0, right = 0; right < size; right++) {
      temp -= abs(s[right] - t[right]);
      while (left < right && temp < 0) {
        temp += abs(s[left] - t[left]);
        left++;
      }

      if (temp >= 0) {
        answer = max(answer, right - left + 1);
      }
    }

    return answer;
  }
};