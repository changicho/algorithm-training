#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N) + M * log_2(M))
// space : O(N + M)
class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int answer = 0;
    for (int i = 0, j = 0; i < g.size() && j < s.size(); j++) {
      if (g[i] <= s[j]) {
        answer++;
        i++;
      }
    }

    return answer;
  }
};