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

// use topological sort
// time : O(N + M + S)
// space : O(N + M + S)
class Solution {
 public:
  vector<string> findAllRecipes(vector<string> &recipes,
                                vector<vector<string>> &ingredients,
                                vector<string> &supplies) {
    int size = recipes.size();

    unordered_map<string, int> inDegrees;
    unordered_map<string, vector<string>> nexts;

    for (int i = 0; i < size; i++) {
      string target = recipes[i];

      for (string &need : ingredients[i]) {
        inDegrees[target]++;

        nexts[need].push_back(target);
      }
    }

    queue<string> q;
    for (string &key : supplies) {
      q.push(key);
    }

    while (!q.empty()) {
      string cur = q.front();
      q.pop();

      for (string &next : nexts[cur]) {
        inDegrees[next]--;

        if (inDegrees[next] == 0) {
          q.push(next);
        }
      }
    }

    vector<string> answer;

    for (string &r : recipes) {
      if (inDegrees[r] == 0) answer.push_back(r);
    }
    return answer;
  }
};