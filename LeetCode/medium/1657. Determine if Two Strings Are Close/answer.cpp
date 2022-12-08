#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & masking
// time : O(N + M)
// space : O(1)
class Solution {
 private:
  vector<int> getCounts(string &word) {
    vector<int> counts(26, 0);

    for (char &c : word) {
      counts[c - 'a']++;
    }

    sort(counts.begin(), counts.end());
    return counts;
  }

  int getMask(string &word) {
    int bit = 0;
    for (char &c : word) {
      bit |= 1 << (c - 'a');
    }
    return bit;
  }

 public:
  bool closeStrings(string word1, string word2) {
    vector<int> count1 = getCounts(word1), count2 = getCounts(word2);
    int bit1 = getMask(word1), bit2 = getMask(word2);
    return count1 == count2 && bit1 == bit2;
  }
};