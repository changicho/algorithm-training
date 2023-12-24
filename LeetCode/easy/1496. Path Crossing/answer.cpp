#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Axis {
    int y, x;

    int convert() { return y * 100000 + x; }
  };
  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  Axis convert(char &c) {
    switch (c) {
      case 'N': {
        return dirs[0];
      }
      case 'S': {
        return dirs[2];
      }
      case 'E': {
        return dirs[3];
      }
      case 'W': {
        return dirs[1];
      }
    }
    return {0, 0};
  }

 public:
  bool isPathCrossing(string path) {
    unordered_set<int> visited;

    Axis cur = {0, 0};
    visited.insert(cur.convert());

    for (char &c : path) {
      Axis dir = convert(c);

      cur.y += dir.y, cur.x += dir.x;
      if (visited.count(cur.convert())) return true;
      visited.insert(cur.convert());
    }
    return false;
  }
};