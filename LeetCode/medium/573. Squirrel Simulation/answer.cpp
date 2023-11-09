#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  int getDist(vector<int>& from, vector<int>& to) {
    return abs(from[0] - to[0]) + abs(from[1] - to[1]);
  }

 public:
  int minDistance(int height, int width, vector<int>& tree,
                  vector<int>& squirrel, vector<vector<int>>& nuts) {
    int nutSize = nuts.size();

    int sum = 0;
    int diff = INT_MAX;
    for (vector<int>& nut : nuts) {
      int sdist = getDist(squirrel, nut);
      int dist = getDist(tree, nut);

      diff = min(diff, sdist - dist);
      sum += dist * 2;
    }

    return sum + diff;
  }
};