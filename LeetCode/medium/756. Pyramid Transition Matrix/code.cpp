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

// use DFS with memoization
// time : O(A^N)
// space : O(N^2)
class Solution {
 private:
  unordered_map<string, vector<char>> um;
  unordered_map<string, bool> dp;

  bool recursive(string& line) {
    int size = line.size();

    if (size == 1) return true;
    if (dp.count(line)) return dp[line];

    vector<vector<char>> ch(size - 1);

    for (int i = 0; i < size - 1; i++) {
      string key = {line[i], line[i + 1]};

      for (char& c : um[key]) {
        ch[i].push_back(c);
      }
    }

    unordered_set<string> us;
    unordered_set<string> visited;

    queue<string> q;
    q.push("");

    while (!q.empty()) {
      string cur = q.front();
      q.pop();

      if (cur.size() == size - 1) {
        us.insert(cur);
        continue;
      }

      for (char& c : ch[cur.size()]) {
        string next = cur + c;
        if (visited.count(next)) continue;
        if (next.size() >= 2 &&
            um.count({next[next.size() - 2], next[next.size() - 1]}) == 0)
          continue;

        visited.insert(next);
        q.push(next);
      }
    }

    bool ret = false;
    for (string next : us) {
      ret |= recursive(next);
      if (ret) break;
    }
    return dp[line] = ret;
  }

 public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    for (string& s : allowed) {
      string key = {s[0], s[1]};
      char c = s[2];

      um[key].push_back(c);
    }

    return recursive(bottom);
  }
};

// use DFS with memoization
// time : O(A^N)
// space : O(N^2)
class Solution {
 private:
  unordered_map<string, vector<char>> um;
  unordered_map<string, bool> dp;

  bool recursive(string& line) {
    int size = line.size();

    if (size == 1) return true;
    if (dp.count(line)) return dp[line];

    vector<vector<char>> ch(size - 1);

    for (int i = 0; i < size - 1; i++) {
      string key = {line[i], line[i + 1]};

      for (char& c : um[key]) {
        ch[i].push_back(c);
      }
    }

    unordered_set<string> us;

    function<void(int, string&)> dfs = [&](int i, string& cur) {
      if (i == size - 1) {
        us.insert(cur);
        return;
      }

      for (char& c : ch[i]) {
        if (cur.size() > 0) {
          string key = {cur.back(), c};
          if (um.count(key) == 0) continue;
        }

        cur.push_back(c);
        dfs(i + 1, cur);
        cur.pop_back();
      }
    };

    string cur = "";
    dfs(0, cur);

    bool ret = false;
    for (string next : us) {
      ret |= recursive(next);
      if (ret) break;
    }
    return dp[line] = ret;
  }

 public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    for (string& s : allowed) {
      string key = {s[0], s[1]};
      char c = s[2];

      um[key].push_back(c);
    }

    return recursive(bottom);
  }
};