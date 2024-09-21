#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort and two pointer
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    int size = tokens.size();

    sort(tokens.begin(), tokens.end());

    int left = 0, right = size - 1;

    int score = 0;
    int answer = 0;
    while (left <= right) {
      if (power >= tokens[left]) {
        score++;
        power -= tokens[left];
        left++;
      } else {
        if (score == 0) break;
        score--;
        power += tokens[right];
        right--;
      }
      answer = max(answer, score);
    }

    return answer;
  }
};