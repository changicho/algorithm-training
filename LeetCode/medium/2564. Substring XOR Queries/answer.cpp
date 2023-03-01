#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash map
// time : O(32 * N + M)
// space : O(32 * N + M)
class Solution {
 public:
  vector<vector<int>> substringXorQueries(string s,
                                          vector<vector<int>>& queries) {
    unordered_map<long long, pair<int, int>> um;

    for (int i = 0; i < s.size(); i++) {
      long long val = 0;
      for (int j = 0; j < 32; j++) {
        if (i + j >= s.size()) break;
        val *= 2;
        val += s[i + j] - '0';

        if (um.count(val) == 0) {
          um[val] = {i, i + j};
        }
        if (val == 0) break;
      }
    }

    vector<vector<int>> answer;
    for (vector<int>& q : queries) {
      long long target = q[0] ^ q[1];

      if (um.count(target) == 0) {
        answer.push_back({-1, -1});
      } else {
        answer.push_back({um[target].first, um[target].second});
      }
    }

    return answer;
  }
};