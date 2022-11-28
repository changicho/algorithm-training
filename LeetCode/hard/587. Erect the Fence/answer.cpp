#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use convex hull
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Point {
    int y, x;

    bool operator<(const Point &B) const {
      if (y != B.y) {
        return y < B.y;
      }
      return x < B.x;
    }
  };

  long long getInnerProduct(Point &a, Point &b, Point &c) {
    return (1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y) -
           (1LL * b.x * a.y + 1LL * c.x * b.y + 1LL * a.x * c.y);
  }

  bool isCCW(Point &a, Point &b, Point &c) {
    return getInnerProduct(a, b, c) >= 0;
  }

  vector<Point> getConvexHull(vector<Point> &points) {
    int size = points.size();

    vector<Point> stk;

    for (int next = 0; next < size; next++) {
      while (stk.size() >= 2) {
        Point second = stk.back();
        stk.pop_back();
        Point first = stk.back();

        if (isCCW(first, second, points[next])) {
          stk.push_back(second);
          break;
        }
      }

      stk.push_back(points[next]);
    }

    return stk;
  }

 public:
  vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
    int size = trees.size();

    if (size <= 3) {
      return trees;
    }

    vector<Point> points;
    for (vector<int> &tree : trees) {
      int y = tree[1], x = tree[0];

      points.push_back({y, x});
    }

    sort(points.begin(), points.end());

    vector<Point> ccwPoints = getConvexHull(points);
    reverse(points.begin(), points.end());
    vector<Point> cwPoints = getConvexHull(points);

    vector<vector<int>> answer;
    for (Point &point : cwPoints) {
      answer.push_back({point.x, point.y});
    }
    for (Point &point : ccwPoints) {
      answer.push_back({point.x, point.y});
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
  }
};