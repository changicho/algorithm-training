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

// use sort & map
// time : O(N^3)
// space : O(N)
class Solution {
 private:
  struct Data {
    string u;
    int t;
    string w;

    bool operator<(const Data &b) const { return t < b.t; }
  };

 public:
  vector<string> mostVisitedPattern(vector<string> &username,
                                    vector<int> &timestamp,
                                    vector<string> &website) {
    int size = username.size();

    vector<Data> arr;
    for (int i = 0; i < size; i++) {
      arr.push_back({username[i], timestamp[i], website[i]});
    }
    sort(arr.begin(), arr.end());

    unordered_map<string, vector<string>> um;

    for (Data &d : arr) {
      um[d.u].push_back(d.w);
    }

    map<vector<string>, unordered_set<string>> visited;
    for (auto &[k, v] : um) {
      string key = k;
      int vSize = v.size();

      for (int i = 0; i < vSize; i++) {
        for (int j = i + 1; j < vSize; j++) {
          for (int k = j + 1; k < vSize; k++) {
            visited[{v[i], v[j], v[k]}].insert(key);
          }
        }
      }
    }

    vector<string> answer;
    int count = 0;
    for (auto &[k, v] : visited) {
      if (v.size() > count) {
        answer = k;
        count = v.size();
      } else if (v.size() == count) {
        answer = min(answer, k);
      }
    }
    return answer;
  }
};