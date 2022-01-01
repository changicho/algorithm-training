#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use atan & sliding window

class Solution {
 private:
  const double PI = 3.14159265;

 public:
  int visiblePoints(vector<vector<int>> &points, int angle,
                    vector<int> &location) {
    vector<double> angles;
    int sames = 0;

    // get angle from all points
    for (vector<int> &point : points) {
      int py = point[1], px = point[0];
      int ly = location[1], lx = location[0];

      int width = px - lx;
      int height = py - ly;

      // find same point
      if (width == 0 && height == 0) {
        sames += 1;
        continue;
      }

      // compress width and height
      if (width == 0 || height == 0) {
        if (width > 0) width = 1;
        if (height > 0) height = 1;
      } else {
        int div = gcd(width, height);
        width /= div;
        height /= div;
      }

      double a = atan2(height, width) * 180 / PI;

      if (a < 0) a += 360;
      angles.push_back(a);
    }

    // sort angles by accending
    sort(angles.begin(), angles.end());

    queue<double> q;
    deque<double> visible;
    set<double> froms;

    for (double &a : angles) {
      q.push(a);
      froms.insert(a);
    }

    int answer = sames;
    // iterate all angles
    for (auto &from : froms) {
      double to = from + angle;

      // use sliding window to find visible points of from ~ to angle
      while (!q.empty() && from <= q.front() && q.front() <= to) {
        double a = q.front();
        visible.push_back(a);
        q.pop();
        // push angle for (from ~ to) range over 360
        // if angle is 10, it is same 370 (360 + 10) degree
        q.push(a + 360);
      }

      while (!visible.empty() && visible.front() < from) {
        visible.pop_front();
      }
      answer = max(answer, sames + (int)visible.size());
    }

    return answer;
  }
};