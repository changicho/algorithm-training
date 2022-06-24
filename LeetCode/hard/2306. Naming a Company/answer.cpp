#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use grouping by prefix
// time : O(N)
// space : O(N)
class Solution {
 public:
  long long distinctNames(vector<string>& ideas) {
    unordered_set<string> suffix[26];
    long long result = 0;

    for (string& idea : ideas) {
      suffix[idea[0] - 'a'].insert(idea.substr(1));
    }

    // a ~ z
    for (int i = 0; i < 26; i++) {
      for (int j = i + 1; j < 26; j++) {
        int duplicate = 0;
        for (string item : suffix[i]) {
          duplicate += suffix[j].count(item);
        }

        result +=
            2 * (suffix[i].size() - duplicate) * (suffix[j].size() - duplicate);
      }
    }

    return result;
  }
};