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

// use brute force
// time : O(N! * N)
// space : O(N! * N)
class Solution {
 public:
  int numTilePossibilities(string tiles) {
    int size = tiles.size();

    unordered_set<string> us;

    string temp = "";
    vector<bool> visited(size, false);

    function<void(int)> dfs = [&](int index) {
      us.insert(temp);

      for (int i = 0; i < size; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        temp.push_back(tiles[i]);

        dfs(index + 1);

        visited[i] = false;
        temp.pop_back();
      }
    };

    dfs(0);

    return us.size() - 1;
  }
};

// use optimized recursion
// time : O(2^N)
// space : O(N)
class Solution {
 private:
  int recursive(int counts[26]) {
    int ret = 0;

    for (int c = 0; c < 26; c++) {
      if (counts[c] == 0) {
        continue;
      }

      ret++;
      counts[c]--;
      ret += recursive(counts);
      counts[c]++;
    }

    return ret;
  }

 public:
  int numTilePossibilities(string tiles) {
    int counts[26] = {0};
    for (char &c : tiles) {
      counts[c - 'A']++;
    }

    return recursive(counts);
  }
};