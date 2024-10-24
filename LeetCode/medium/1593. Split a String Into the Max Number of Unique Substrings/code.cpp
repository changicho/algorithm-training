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

// use DFS & backtracking
// time : O(N * 2^N)
// space : O(N)
class Solution {
 private:
  int answer = 0;

  void recursive(int i, string &s, string &temp,
                 unordered_set<string> &visited) {
    if ((s.size() - i) + visited.size() < answer) return;

    if (s.size() == i) {
      answer = max(answer, (int)visited.size());
      return;
    }

    // keep
    temp.push_back(s[i]);
    recursive(i + 1, s, temp, visited);

    // cut
    if (temp.size() > 0 && visited.count(temp) == 0) {
      visited.insert(temp);

      string newTemp = "";
      recursive(i + 1, s, newTemp, visited);

      visited.erase(temp);
    }

    temp.pop_back();
  }

 public:
  int maxUniqueSplit(string s) {
    string temp = "";
    unordered_set<string> visited;

    recursive(0, s, temp, visited);

    return answer;
  }
};