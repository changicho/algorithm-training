#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int scoreOfString(string s) {
    int size = s.size();

    int answer = 0;
    for (int i = 0; i < size - 1; i++) {
      answer += abs(s[i] - s[i + 1]);
    }

    return answer;
  }
};
