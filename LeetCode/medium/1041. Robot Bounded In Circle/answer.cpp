#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use set

class Solution {
 private:
  pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  bool isRobotBounded(string instructions) {
    set<pair<pair<int, int>, int>> hashSet;

    pair<int, int> axis = {0, 0};
    int dir = 0;
    hashSet.insert({axis, dir});

    for (int i = 0; i < 4; i++) {
      pair<pair<int, int>, int> last;

      for (char c : instructions) {
        switch (c) {
          case 'G': {
            axis.first += dirs[dir].first;
            axis.second += dirs[dir].second;
            break;
          }
          case 'L': {
            dir = (dir - 1 + 4) % 4;
            break;
          }
          case 'R': {
            dir = (dir + 1 + 4) % 4;
            break;
          }
        }

        last = {axis, dir};
      }

      if (hashSet.count(last) > 0) return true;
      hashSet.insert(last);
    }

    return false;
  }
};

// use hash set

class Solution {
 private:
  pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  string convert(pair<pair<int, int>, int> status) {
    string ret = "";
    ret += to_string(status.first.first) + "/";
    ret += to_string(status.first.second) + "/";
    ret += to_string(status.second);
    return ret;
  }

 public:
  bool isRobotBounded(string instructions) {
    unordered_set<string> hashSet;

    pair<int, int> axis = {0, 0};
    int dir = 0;
    hashSet.insert(convert({axis, dir}));

    for (int i = 0; i < 4; i++) {
      pair<pair<int, int>, int> last;

      for (char c : instructions) {
        switch (c) {
          case 'G': {
            axis.first += dirs[dir].first;
            axis.second += dirs[dir].second;
            break;
          }
          case 'L': {
            dir = (dir - 1 + 4) % 4;
            break;
          }
          case 'R': {
            dir = (dir + 1 + 4) % 4;
            break;
          }
        }

        last = {axis, dir};
      }

      string status = convert(last);
      if (hashSet.count(status) > 0) return true;
      hashSet.insert(status);
    }

    return false;
  }
};

// use start position checking

class Solution {
 public:
  bool isRobotBounded(string instructions) {
    pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    pair<int, int> axis = {0, 0};
    int dir = 0;

    for (int i = 0; i < 4; i++) {
      for (char c : instructions) {
        switch (c) {
          case 'G': {
            axis.first += dirs[dir].first;
            axis.second += dirs[dir].second;
            break;
          }
          case 'L': {
            dir = (dir - 1 + 4) % 4;
            break;
          }
          case 'R': {
            dir = (dir + 1 + 4) % 4;
            break;
          }
        }
      }

      if (axis.first == 0 && axis.second == 0 && dir == 0) return true;
    }

    return false;
  }
};
