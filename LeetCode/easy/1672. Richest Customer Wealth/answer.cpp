#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force

class Solution {
 public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int answer = 0;

    for (vector<int> &account : accounts) {
      int cur = 0;
      for (int &w : account) {
        cur += w;
      }
      answer = max(answer, cur);
    }

    return answer;
  }
};