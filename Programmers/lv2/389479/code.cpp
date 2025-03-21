#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use simulation
// time : O(1)
// space : O(1)
int solution(vector<int> players, int m, int k) {
  int reserved[24] = {
      0,
  };
  int server = 0;

  int answer = 0;
  for (int time = 0; time < 24; time++) {
    server -= reserved[time];

    int player = players[time];
    int capacity = (server + 1) * m - 1;

    int diff = player - capacity;

    int needed = max(0, (int)ceil((double)diff / m));

    answer += needed;
    server += needed;

    if (time + k < 24) {
      reserved[time + k] += needed;
    }
  }

  return answer;
}