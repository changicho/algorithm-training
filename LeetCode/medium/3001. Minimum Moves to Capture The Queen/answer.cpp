#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(1)
// space : O(1)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  Axis diagonalDirs[4] = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};

 public:
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    Axis rook = {a, b}, bishop = {c, d}, queen = {e, f};

    // find rook
    for (Axis &dir : dirs) {
      Axis cur = queen;
      for (int i = 0; i < 8; i++) {
        cur.y += dir.y;
        cur.x += dir.x;

        if (cur.y == bishop.y && cur.x == bishop.x) break;
        if (cur.y == rook.y && cur.x == rook.x) return 1;
      }
    }

    // find bishop
    for (Axis &dir : diagonalDirs) {
      Axis cur = queen;
      for (int i = 0; i < 8; i++) {
        cur.y += dir.y;
        cur.x += dir.x;

        if (cur.y == bishop.y && cur.x == bishop.x) return 1;
        if (cur.y == rook.y && cur.x == rook.x) break;
      }
    }

    return 2;
  }
};

// use compare
// time : O(1)
// space : O(1)
// (a, b) denotes the position of the white rook.
// (c, d) denotes the position of the white bishop.
// (e, f) denotes the position of the black queen.
class Solution {
 private:
  struct Axis {
    int y, x;
  };

 public:
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    Axis rook = {a, b}, bishop = {c, d}, queen = {e, f};

    if (rook.y == queen.y) {
      if (bishop.y != rook.y) return 1;

      vector<int> arr = {rook.x, bishop.x, queen.x};
      sort(arr.begin(), arr.end());

      if (bishop.x != arr[1]) return 1;
    }
    if (rook.x == queen.x) {
      if (bishop.x != rook.x) return 1;

      vector<int> arr = {rook.y, bishop.y, queen.y};
      sort(arr.begin(), arr.end());

      if (bishop.y != arr[1]) return 1;
    }

    if ((bishop.y - bishop.x) == (queen.y - queen.x)) {
      if ((bishop.y - bishop.x) != (rook.y - rook.x)) return 1;

      // check x
      vector<int> arr = {bishop.x, rook.x, queen.x};
      sort(arr.begin(), arr.end());

      if (rook.x != arr[1]) return 1;
    }

    if ((bishop.y + bishop.x) == (queen.y + queen.x)) {
      if ((bishop.y + bishop.x) != (rook.y + rook.x)) return 1;

      // check y
      vector<int> arr = {bishop.y, rook.y, queen.y};
      sort(arr.begin(), arr.end());

      if (rook.y != arr[1]) return 1;
    }
    return 2;
  }
};