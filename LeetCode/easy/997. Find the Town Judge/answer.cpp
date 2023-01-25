#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use count
// time : O(M)
// space : O(N)
class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> counts(n + 1, 0);
    vector<bool> trustSomeones(n + 1, false);

    for (vector<int>& t : trust) {
      int from = t[0], to = t[1];
      trustSomeones[from] = true;
      counts[to]++;
    }

    int answer = -1;
    for (int i = 1; i <= n; i++) {
      if (counts[i] == n - 1 && trustSomeones[i] == false) {
        if (answer != -1) return -1;
        answer = i;
      }
    }
    return answer;
  }
};