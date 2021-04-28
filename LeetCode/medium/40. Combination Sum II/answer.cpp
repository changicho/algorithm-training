#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use backtracking with set

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    set<vector<int>> s;
    sort(candidates.begin(), candidates.end());

    vector<int> array;
    recursive(-1, target, array, candidates, s);

    vector<vector<int>> answers;

    for (vector<int> cur : s) {
      answers.push_back(cur);
    }

    return answers;
  }

  void recursive(int index, int diff, vector<int>& array, vector<int>& candidates, set<vector<int>>& s) {
    if (diff == 0) {
      s.insert(array);
      return;
    }

    int size = candidates.size();
    for (int i = index + 1; i < size; i++) {
      int cur = candidates[i];
      if (diff - cur < 0) break;

      array.push_back(cur);
      recursive(i, diff - cur, array, candidates, s);
      array.pop_back();
    }
  }
};

// use backtracking

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> answers;
    sort(candidates.begin(), candidates.end());

    vector<int> array;
    recursive(-1, target, array, candidates, answers);

    return answers;
  }

  void recursive(int index, int diff, vector<int>& array, vector<int>& candidates, vector<vector<int>>& answers) {
    if (diff == 0) {
      answers.push_back(array);
      return;
    }

    int size = candidates.size();
    for (int i = index + 1; i < size; i++) {
      int cur = candidates[i];
      if (diff - cur < 0) break;

      array.push_back(cur);
      recursive(i, diff - cur, array, candidates, answers);
      array.pop_back();
      while (i + 1 < size && candidates[i] == candidates[i + 1]) {
        i++;
      }
    }
  }
};