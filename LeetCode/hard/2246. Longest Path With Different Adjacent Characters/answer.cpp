#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS
// time : O(N)
// space  :O(N)
class Solution {
 private:
  vector<vector<int>> children;
  string s;
  int answer = 1;

  int recursive(int node) {
    // leftPath + cur + rightPath
    int first = 0, second = 0;
    for (int& child : children[node]) {
      int curLen = recursive(child);

      if (s[child] != s[node]) {
        if (curLen > first) {
          second = first;
          first = curLen;
        } else if (curLen > second) {
          second = curLen;
        }
      }
    }

    answer = max(answer, first + second + 1);

    return first + 1;
  }

 public:
  int longestPath(vector<int>& parent, string s) {
    int size = parent.size();

    this->s = s;

    children.resize(size);
    for (int n = 1; n < size; n++) {
      children[parent[n]].push_back(n);
    }

    recursive(0);

    return answer;
  }
};