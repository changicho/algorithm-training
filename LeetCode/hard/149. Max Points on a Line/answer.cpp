#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use brute force

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