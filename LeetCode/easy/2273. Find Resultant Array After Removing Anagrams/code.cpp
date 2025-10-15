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

// use one pass with count
// time : O(N * L)
// space : O(N * L)
class Solution {
 private:
  bool isAnagram(string &a, string &b) {
    int count[26] = {
        0,
    };
    for (char &c : a) {
      count[c - 'a']++;
    }
    for (char &c : b) {
      count[c - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (count[i] != 0) return false;
    }
    return true;
  }

 public:
  vector<string> removeAnagrams(vector<string> &words) {
    vector<string> answer;

    for (string &w : words) {
      if (!answer.empty() && isAnagram(answer.back(), w)) continue;
      answer.push_back(w);
    }
    return answer;
  }
};