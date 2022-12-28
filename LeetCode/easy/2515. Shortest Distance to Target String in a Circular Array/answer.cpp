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
  int closetTarget(vector<string>& words, string target, int startIndex) {
    int size = words.size();

    int answer = INT_MAX;
    for (int i = 0; i < size; i++) {
      if (words[i] != target) continue;

      int first = abs(startIndex - i);
      int second = abs(size - first);

      answer = min({answer, first, second});
    }

    return answer == INT_MAX ? -1 : answer;
  }
};