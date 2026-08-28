#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// greedy DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  int count[26] = {
      0,
  };
  string answer = "";

  void dfs(string& target, int index, string& temp, bool beforeFit) {
    if (answer != "") return;
    if (index == target.size()) {
      if (temp > target) {
        answer = temp;
      }

      return;
    }

    for (int i = beforeFit ? target[index] - 'a' : 0; i < 26; i++) {
      if (count[i] == 0) continue;
      count[i]--;

      temp += ('a' + i);
      dfs(target, index + 1, temp, beforeFit && target[index] == temp.back());
      temp.pop_back();
      count[i]++;
    }
  }

 public:
  string lexGreaterPermutation(string s, string target) {
    for (char& c : s) {
      count[c - 'a']++;
    }

    string temp = "";
    dfs(target, 0, temp, true);

    return answer;
  }
};