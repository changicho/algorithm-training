#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_map<string, string> um;

    for (vector<string>& path : paths) {
      um[path[0]] = path[1];
    }

    string start = paths[0][0];
    string answer = start;
    while (um.count(start) > 0) {
      start = um[start];
      answer = start;
    }
    return answer;
  }
};

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_map<string, int> outDegrees;

    for (vector<string>& path : paths) {
      string from = path[0], to = path[1];

      outDegrees[from]++;
    }

    string answer = paths[0][0];
    for (vector<string>& path : paths) {
      string to = path[1];
      if (outDegrees[to] == 0) {
        answer = to;
        break;
      }
    }
    return answer;
  }
};