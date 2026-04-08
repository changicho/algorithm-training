#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// simulation
// time : O(R + C)
// space : O(1)
class Robot {
 private:
  struct Axis {
    int y, x;
  };

  int y = 0, x = 0;
  int width, height;
  int length;

  int dir = 0;
  Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  string dirString[4] = {"East", "North", "West", "South"};

  bool checkOverflow() {
    int ny = y + dirs[dir].y;
    int nx = x + dirs[dir].x;
    if (ny < 0 || ny >= height || nx < 0 || nx >= width) return true;
    return false;
  }

 public:
  Robot(int width, int height) {
    this->width = width;
    this->height = height;
    length = width * 2 - 2 + height * 2 - 2;
  }

  void step(int num) {
    num--;
    num %= length;
    num++;

    while (num > 0) {
      if (checkOverflow()) {
        dir++;
        dir %= 4;
      }

      int diff = 0;
      if (dir == 0) {
        diff = min(num, width - 1 - x);
      } else if (dir == 1) {
        diff = min(num, height - 1 - y);
      } else if (dir == 2) {
        diff = min(num, x);
      } else if (dir == 3) {
        diff = min(num, y);
      }

      y = y + diff * dirs[dir].y;
      x = x + diff * dirs[dir].x;

      num -= diff;
    }
  }

  vector<int> getPos() { return {x, y}; }

  string getDir() { return dirString[dir]; }
};

// simulation
// time : O(1)
// space : O(1)
class Robot {
 private:
  int width, height, length;
  int pos = 0;
  bool hasMoved = false;

 public:
  Robot(int width, int height) {
    this->width = width;
    this->height = height;
    length = 2 * (width - 1 + height - 1);
  }

  void step(int num) {
    hasMoved = true;
    pos = (pos + num) % length;
  }

  vector<int> getPos() {
    int h = height - 1, w = width - 1;

    if (pos < width) return {pos, 0};
    if (pos <= w + h) return {w, pos - w};
    if (pos <= 2 * w + h) return {w - (pos - (w + h)), h};
    return {0, h - (pos - (2 * w + h))};
  }

  string getDir() {
    int h = height - 1, w = width - 1;

    if (!hasMoved) return "East";
    if (pos == 0) return "South";
    if (pos <= w) return "East";
    if (pos <= w + h) return "North";
    if (pos <= 2 * w + h) return "West";
    return "South";
  }
};