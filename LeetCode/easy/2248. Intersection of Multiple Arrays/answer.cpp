#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N * log_2(N)))
// space : O(N)
class Solution {
 private:
  vector<int> intersection(vector<int> &a, vector<int> &b) {
    unordered_set<int> visited;
    for (int &n : a) {
      visited.insert(n);
    }

    vector<int> same;
    for (int &n : b) {
      if (visited.count(n) > 0) {
        same.push_back(n);
      }
    }
    return same;
  }

 public:
  vector<int> intersection(vector<vector<int>> &nums) {
    vector<int> ret = nums.front();

    for (vector<int> &array : nums) {
      ret = intersection(ret, array);
    }
    sort(ret.begin(), ret.end());
    return ret;
  }
};

// use count
// time : O(N * log_2(N)))
// space : O(N)
class Solution {
 private:
 public:
  vector<int> intersection(vector<vector<int>> &nums) {
    int size = nums.size();
    unordered_map<int, int> counts;

    for (vector<int> &array : nums) {
      for (int &n : array) {
        counts[n]++;
      }
    }

    vector<int> ret;
    for (auto &[key, val] : counts) {
      if (val == size) ret.push_back(key);
    }
    sort(ret.begin(), ret.end());
    return ret;
  }
};