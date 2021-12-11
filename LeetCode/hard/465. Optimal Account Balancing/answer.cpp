#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use DFS

class Solution {
 private:
  vector<int> debts;  // all debts (not zero)

  // min number of transactions to settle starting from debt[s]
  int dfs(int start) {
    while (start < debts.size() && debts[start] == 0) {
      start++;  // get next debt index
    }

    int minimum = INT_MAX;
    for (int i = start + 1; i < debts.size(); ++i) {
      // skip if debts[start], debts[i] are same sign
      if (debts[i] * debts[start] > 0) continue;

      debts[i] += debts[start];
      minimum = min(minimum, 1 + dfs(start + 1));
      debts[i] -= debts[start];
    }

    return minimum < INT_MAX ? minimum : 0;
  }

 public:
  int minTransfers(vector<vector<int>>& transactions) {
    unordered_map<int, int> diffs;

    for (vector<int>& transaction : transactions) {
      int from = transaction[0], to = transaction[1], amount = transaction[2];

      diffs[from] -= amount;
      diffs[to] += amount;
    }

    // only deal with non-zero debts
    for (auto& p : diffs) {
      if (p.second == 0) continue;

      debts.push_back(p.second);
    }

    return dfs(0);
  }
};

// use DFS with optimize (remove duplicate)

class Solution {
 private:
  vector<int> debts;  // all debts (not zero)

  // min number of transactions to settle starting from debt[s]
  int dfs(int start) {
    while (start < debts.size() && debts[start] == 0) {
      start++;  // get next debt index
    }

    int minimum = INT_MAX;
    int prev = 0;

    for (int i = start + 1; i < debts.size(); ++i) {
      // skip already tested or same sign debt
      if (debts[i] != prev && debts[i] * debts[start] >= 0) continue;

      debts[i] += debts[start];
      minimum = min(minimum, 1 + dfs(start + 1));
      debts[i] -= debts[start];

      prev = debts[i];
    }

    return minimum < INT_MAX ? minimum : 0;
  }

 public:
  int minTransfers(vector<vector<int>>& transactions) {
    unordered_map<int, int> diffs;

    for (vector<int>& t : transactions) {
      int from = t[0], to = t[1], amount = t[2];

      diffs[from] -= amount;
      diffs[to] += amount;
    }

    // only deal with non-zero debts
    for (auto& p : diffs) {
      if (p.second == 0) continue;

      debts.push_back(p.second);
    }

    return dfs(0);
  }
};