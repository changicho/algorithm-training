#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefix sum & bit mask
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    int length = s.size();

    vector<int> fromLeft(length, 0);
    vector<int> fromRight(length, 0);

    for (int i = 0; i < length; i++) {
      if (i - 1 >= 0) {
        fromLeft[i] = fromLeft[i - 1];
      }
      fromLeft[i] |= 1 << (s[i] - 'a');
    }
    for (int i = length - 1; i >= 0; i--) {
      if (i + 1 < length) {
        fromRight[i] = fromRight[i + 1];
      }
      fromRight[i] |= 1 << (s[i] - 'a');
    }

    bool visited[26][26] = {
        false,
    };
    int answer = 0;
    for (int i = 1; i < length - 1; i++) {
      int cur = s[i] - 'a';

      int left = i - 1, right = i + 1;

      for (int j = 0; j < 26; j++) {
        int bit = 1 << j;
        if (fromLeft[left] & bit && fromRight[right] & bit) {
          if (visited[cur][j]) continue;
          visited[cur][j] = true;

          answer++;
        }
      }
    }
    return answer;
  }
};