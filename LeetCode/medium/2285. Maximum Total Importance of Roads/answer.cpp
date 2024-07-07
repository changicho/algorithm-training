#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use counting sort
// time : O(V + E)
// space : O(V)
class Solution {
 public:
  long long maximumImportance(int n, vector<vector<int>> &roads) {
    int inDegrees[50001] = {
        0,
    };

    for (vector<int> &e : roads) {
      int a = e[0], b = e[1];

      inDegrees[a]++;
      inDegrees[b]++;
    }

    int counts[50001] = {
        0,
    };
    for (int &inDegree : inDegrees) {
      counts[inDegree]++;
    }

    long long answer = 0;
    for (long long score = n, cur = n; cur >= 0; cur--) {
      while (counts[cur] > 0) {
        answer += score * cur;
        counts[cur]--;
        score--;
      }
    }

    return answer;
  }
};