#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> copied = heights;

    sort(copied.begin(), copied.end());

    int answer = 0;
    for (int i = 0; i < heights.size(); i++) {
      if (heights[i] != copied[i]) answer++;
    }
    return answer;
  }
};