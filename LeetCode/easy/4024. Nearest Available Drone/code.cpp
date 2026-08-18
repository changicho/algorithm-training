#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
    int answer = -1;
    int dist = INT_MAX;

    int size = drones.size();

    for (int i = 0; i < size; i++) {
      vector<int>& d = drones[i];
      int curDist = abs(d[0] - target[0]) + abs(d[1] - target[1]);
      if (curDist > d[2]) continue;

      if (curDist < dist) {
        answer = i;
        dist = curDist;
      }
    }

    return answer;
  }
};