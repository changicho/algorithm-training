#include <algorithm>
#include <climits>
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

// use queue
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>> answer;

    queue<int> q;
    for (int& n : nums) {
      q.push(n);
    }

    while (!q.empty()) {
      unordered_set<int> us;

      int size = q.size();
      while (size--) {
        int cur = q.front();
        q.pop();

        if (us.count(cur) == 0) {
          us.insert(cur);
        } else {
          q.push(cur);
        }
      }

      vector<int> line;
      for (int n : us) {
        line.push_back(n);
      }
      answer.push_back(line);
    }
    return answer;
  }
};