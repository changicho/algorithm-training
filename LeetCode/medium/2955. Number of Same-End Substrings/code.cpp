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

// use binary search
// time : O(N + Q * log_2(N))
// space : O(N + Q)
class Solution {
 private:
  int getCount(vector<int> &indexes, int left, int right) {
    int count = upper_bound(indexes.begin(), indexes.end(), right) -
                lower_bound(indexes.begin(), indexes.end(), left);
    return count;
  }

 public:
  vector<int> sameEndSubstringCount(string s, vector<vector<int>> &queries) {
    int size = s.size();

    vector<int> indexes[26];

    for (int i = 0; i < size; i++) {
      indexes[s[i] - 'a'].push_back(i);
    }

    vector<int> answer;
    for (vector<int> &q : queries) {
      int left = q[0], right = q[1];
      int cur = 0;

      for (int c = 0; c < 26; c++) {
        int count = getCount(indexes[c], left, right);

        cur += (count + 1) * count / 2;
      }

      answer.push_back(cur);
    }
    return answer;
  }
};

// use prefix sum
// time : O(N + Q)
// space : O(N + Q)
class Solution {
 public:
  vector<int> sameEndSubstringCount(string s, vector<vector<int>> &queries) {
    int size = s.size();

    vector<vector<int>> counts(26, vector<int>(size + 1));

    for (int i = 0; i < size; i++) {
      for (int c = 0; c < 26; c++) {
        counts[c][i + 1] = counts[c][i];
        if (s[i] - 'a' == c) counts[c][i + 1]++;
      }
    }

    vector<int> answer;
    for (vector<int> &q : queries) {
      int left = q[0], right = q[1];

      int cur = 0;
      for (int c = 0; c < 26; c++) {
        int count = counts[c][right + 1] - counts[c][left];
        cur += (count + 1) * count / 2;
      }

      answer.push_back(cur);
    }
    return answer;
  }
};