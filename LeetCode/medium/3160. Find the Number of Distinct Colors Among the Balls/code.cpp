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

// use hash map count
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> balls;

    unordered_map<int, int> counts;
    vector<int> answer;
    for (vector<int>& q : queries) {
      int key = q[0], color = q[1];
      int before = balls[key];

      if (before != 0) {
        counts[before]--;
        if (counts[before] == 0) {
          counts.erase(before);
        }
      }

      balls[key] = color;
      counts[color]++;

      answer.push_back(counts.size());
    }

    return answer;
  }
};