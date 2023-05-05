#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time: O(N)
// space : O(1)
class Solution {
 public:
  int maxVowels(string s, int k) {
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int counts[26] = {
        0,
    };
    int size = s.size();

    int answer = 0;
    for (int right = 0; right < size; right++) {
      counts[s[right] - 'a']++;

      int left = right - k;
      if (left >= 0) {
        counts[s[left] - 'a']--;
      }

      int cur = 0;
      for (char &v : vowels) {
        cur += counts[v - 'a'];
      }
      answer = max(answer, cur);
    }
    return answer;
  }
};