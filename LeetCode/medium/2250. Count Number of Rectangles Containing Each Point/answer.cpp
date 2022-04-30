#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O((P + N) * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> countRectangles(vector<vector<int>>& rectangles,
                              vector<vector<int>>& points) {
    vector<vector<int>> recsByY(101);

    for (vector<int>& rec : rectangles) {
      recsByY[rec[1]].push_back(rec[0]);
    }
    for (vector<int>& recs : recsByY) {
      sort(recs.begin(), recs.end());
    }

    vector<int> answer;
    for (vector<int>& p : points) {
      int count = 0;

      for (int y = p[1]; y < 101; y++) {
        auto it = lower_bound(recsByY[y].begin(), recsByY[y].end(), p[0]);
        count += recsByY[y].end() - it;
      }

      answer.push_back(count);
    }
    return answer;
  }
};