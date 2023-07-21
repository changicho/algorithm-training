#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set
// time : O(C)
// space : O(C)
class Solution {
 private:
  vector<vector<int>> cornerDiffs = {{-1, -1}, {-1, 0}, {0, -1}, {0, 0}};

  long long convert(int y, int x) { return y * 1000000LL + x; }

 public:
  vector<long long> countBlackBlocks(int m, int n,
                                     vector<vector<int>> &coordinates) {
    // y : m, x : n
    vector<long long> answer(5);

    unordered_set<long long> us;
    for (vector<int> &coord : coordinates) {
      int y = coord[0], x = coord[1];

      us.insert(convert(y, x));
    }

    unordered_set<long long> visited;

    for (vector<int> &cur : coordinates) {
      int y = cur[0], x = cur[1];

      for (vector<int> &cornerDiff : cornerDiffs) {
        int oy = y + cornerDiff[0], ox = x + cornerDiff[1];

        if (oy < 0 || oy >= m - 1 || ox < 0 || ox >= n - 1) continue;
        long long key = convert(oy, ox);
        if (visited.count(key) > 0) continue;
        visited.insert(key);

        int count = 0;
        if (us.count(convert(oy, ox))) count++;
        if (us.count(convert(oy, ox + 1))) count++;
        if (us.count(convert(oy + 1, ox))) count++;
        if (us.count(convert(oy + 1, ox + 1))) count++;

        answer[count]++;
      }
    }

    long long total = (long long)(m - 1) * (n - 1);
    answer[0] = total - answer[1] - answer[2] - answer[3] - answer[4];
    return answer;
  }
};