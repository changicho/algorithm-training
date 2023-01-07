#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use sort & stack
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  bool isOverlapped(vector<int> &a, vector<int> &b) {
    return a.back() >= b.front();
  }

 public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(),
         [](vector<int> &a, vector<int> &b) { return a.back() < b.back(); });

    stack<vector<int>> stk;
    for (vector<int> &p : points) {
      if (!stk.empty() && isOverlapped(stk.top(), p)) {
        vector<int> temp = stk.top();
        stk.pop();

        stk.push({p.front(), temp.back()});
      } else {
        stk.push(p);
      }
    }

    return stk.size();
  }
};

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  bool isOverlapped(vector<int> &a, vector<int> &b) {
    return a.back() >= b.front();
  }

 public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
      if (a.back() == b.back()) return a.front() > b.front();
      return a.back() < b.back();
    });

    int arrows = 1;
    int lastRight = points.front().back();
    for (vector<int> &p : points) {
      int left = p.front(), right = p.back();

      if (lastRight < left) {
        arrows++;
        lastRight = right;
      }
    }
    return arrows;
  }
};