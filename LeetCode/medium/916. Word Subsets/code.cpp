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

// use count
// time : O(N + M)
// space : O(N)
class Solution {
 private:
  bool isValid(vector<int> &count1, vector<int> &count2) {
    for (int i = 0; i < 26; i++) {
      if (count2[i] > count1[i]) {
        return false;
      }
    }
    return true;
  }

 public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    vector<int> target(26, 0);

    for (string &word : words2) {
      vector<int> count(26, 0);

      for (char &c : word) {
        count[c - 'a']++;
      }

      for (int i = 0; i < 26; i++) {
        target[i] = max(target[i], count[i]);
      }
    }

    vector<string> answer;
    for (string &word : words1) {
      vector<int> count(26, 0);
      for (char &c : word) {
        count[c - 'a']++;
      }

      bool flag = true;
      if (!isValid(count, target)) {
        flag = false;
      }

      if (flag) answer.emplace_back(word);
    }
    return answer;
  }
};