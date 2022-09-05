#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool checkDistances(string s, vector<int>& distance) {
    vector<int> dist(26, 0);
    vector<int> lastIdx(26, -1);

    for (int i = 0; i < s.length(); i++) {
      if (lastIdx[s[i] - 'a'] == -1) {
        lastIdx[s[i] - 'a'] = i;
        continue;
      }
      dist[s[i] - 'a'] = i - lastIdx[s[i] - 'a'] - 1;
    }

    for (int i = 0; i < 26; i++) {
      if (lastIdx[i] == -1) continue;
      if (dist[i] != distance[i]) return false;
    }
    return true;
  }
};