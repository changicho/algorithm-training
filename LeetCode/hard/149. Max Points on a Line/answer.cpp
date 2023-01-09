#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  string getGradient(vector<int>& a, vector<int>& b) {
    int yDiff = a[0] - b[0];
    int xDiff = a[1] - b[1];

    int divisor = gcd(yDiff, xDiff);
    yDiff /= divisor;
    xDiff /= divisor;

    return to_string(yDiff) + "/" + to_string(xDiff);
  }

 public:
  int maxPoints(vector<vector<int>>& points) {
    int size = points.size();
    int answer = 1;

    for (vector<int>& from : points) {
      unordered_map<string, int> um;

      for (vector<int>& to : points) {
        if (from[0] == to[0] && from[1] == to[1]) continue;

        string gradient = getGradient(from, to);

        um[gradient] += 1;

        answer = max(answer, um[gradient] + 1);
      }
    }

    return answer;
  }
};

// use brute force
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  double getDiff(vector<int>& a, vector<int>& b) {
    double first = a.front() - b.front();
    double second = a.back() - b.back();

    return first / second;
  }

 public:
  int maxPoints(vector<vector<int>>& points) {
    // [diff, startPoint]

    int answer = 1;
    int size = points.size();
    for (int i = 0; i < size; i++) {
      unordered_map<double, int> counts;

      for (int j = 0; j < size; j++) {
        if (i == j) continue;

        vector<int> a = points[i], b = points[j];

        double diff = getDiff(a, b);
        counts[diff]++;
      }

      for (auto [key, val] : counts) {
        answer = max(answer, val + 1);
      }
    }

    return answer;
  }
};