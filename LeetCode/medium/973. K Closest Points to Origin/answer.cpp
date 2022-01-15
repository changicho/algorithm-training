#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sort

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {
      return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
    });

    vector<vector<int>> answer;
    for (int i = 0; i < k; i++) {
      answer.push_back(points[i]);
    }
    return answer;
  }
};

// use heap

class Solution {
 private:
  int getDistance(vector<int> &point) {
    return point[0] * point[0] + point[1] * point[1];
  }

 public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<pair<int, int>> maxHeap;  // distance, index

    for (int i = 0; i < points.size(); i++) {
      pair<int, int> entry = {getDistance(points[i]), i};
      if (maxHeap.size() < k) {
        maxHeap.push(entry);
      } else if (entry.first < maxHeap.top().first) {
        maxHeap.pop();
        maxHeap.push(entry);
      }
    }

    vector<vector<int>> answer;
    while (!maxHeap.empty()) {
      int entryIndex = maxHeap.top().second;
      maxHeap.pop();
      answer.push_back(points[entryIndex]);
    }
    return answer;
  }
};