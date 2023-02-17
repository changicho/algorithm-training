#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash map
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2,
                           vector<vector<string>>& similarPairs) {
    if (sentence1.size() != sentence2.size()) return false;
    unordered_map<string, unordered_set<string>> um1;

    for (vector<string>& pair : similarPairs) {
      string a = pair[0], b = pair[1];
      um1[a].insert(b);
      um1[b].insert(a);
    }

    int size = sentence1.size();
    for (int i = 0; i < size; i++) {
      string a = sentence1[i], b = sentence2[i];

      if (a == b) continue;
      if (um1[a].count(b) == 0 || um1[b].count(a) == 0) {
        return false;
      }
    }
    return true;
  }
};