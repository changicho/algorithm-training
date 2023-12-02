#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxDistance(vector<vector<int>>& arrays) {
    int size = arrays.size();

    int minimum = arrays[0].front();
    int maximum = arrays[0].back();

    int answer = 0;
    for (int i = 1; i < size; i++) {
      int fromBack = abs(arrays[i].back() - minimum);
      int fromFront = abs(maximum - arrays[i].front());

      answer = max(answer, fromBack);
      answer = max(answer, fromFront);

      minimum = min(minimum, arrays[i].front());
      maximum = max(maximum, arrays[i].back());
    }

    return answer;
  }
};