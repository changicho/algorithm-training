#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use simulation
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> circularGameLosers(int n, int k) {
    bool visited[51] = {
        false,
    };

    int cur = 0;
    int step = 1;
    while (visited[cur] == false) {
      visited[cur] = true;

      cur += (k * step);
      cur %= n;
      step++;
    }

    vector<int> answer;
    for (int i = 0; i < n; i++) {
      if (visited[i] == false) {
        answer.push_back(i + 1);
      }
    }
    return answer;
  }
};