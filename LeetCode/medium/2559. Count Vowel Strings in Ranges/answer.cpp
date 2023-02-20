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

// use prefix sum
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  bool isVowel(char c) { return vowels.count(c) > 0; }

 public:
  vector<int> vowelStrings(vector<string>& words,
                           vector<vector<int>>& queries) {
    int size = words.size();
    vector<bool> isVowelCase(size, false);

    for (int i = 0; i < size; i++) {
      if (isVowel(words[i].front()) && isVowel(words[i].back())) {
        isVowelCase[i] = true;
      }
    }

    vector<int> prefixSum(size + 1, 0);
    for (int i = 1; i <= size; i++) {
      prefixSum[i] = prefixSum[i - 1] + isVowelCase[i - 1];
    }

    vector<int> answer;
    for (vector<int>& q : queries) {
      int l = q[0], r = q[1];

      int cur = prefixSum[r + 1] - prefixSum[l];
      answer.push_back(cur);
    }
    return answer;
  }
};