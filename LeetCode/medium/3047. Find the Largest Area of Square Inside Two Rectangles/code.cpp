#include <algorithm>
#include <climits>
#include <cmath>
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

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 private:
  long long calc(vector<int>& aBottomLeft, vector<int>& aTopRight,
                 vector<int>& bBottomLeft, vector<int>& bTopRight) {
    long long x =
        min(aTopRight[0], bTopRight[0]) - max(aBottomLeft[0], bBottomLeft[0]);
    long long y =
        min(aTopRight[1], bTopRight[1]) - max(aBottomLeft[1], bBottomLeft[1]);

    long long length = min(y, x);
    if (length < 0) return 0;

    return length * length;
  }

 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    int size = bottomLeft.size();

    long long answer = 0;
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        long long cur =
            calc(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]);

        answer = max(answer, cur);
      }
    }

    return answer;
  }
};

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 private:
  long long calc(vector<int>& aBottomLeft, vector<int>& aTopRight,
                 vector<int>& bBottomLeft, vector<int>& bTopRight) {
    bool xOverlap =
        (bBottomLeft[0] <= aTopRight[0] && aBottomLeft[0] <= bTopRight[0]);
    bool yOverlap =
        (bBottomLeft[1] <= aTopRight[1] && aBottomLeft[1] <= bTopRight[1]);

    if (!xOverlap || !yOverlap) return 0;

    long long x =
        min(aTopRight[0], bTopRight[0]) - max(aBottomLeft[0], bBottomLeft[0]);
    long long y =
        min(aTopRight[1], bTopRight[1]) - max(aBottomLeft[1], bBottomLeft[1]);

    long long length = min(y, x);
    if (length < 0) return 0;

    return length * length;
  }

 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    int size = bottomLeft.size();

    long long answer = 0;
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        long long cur =
            calc(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]);

        answer = max(answer, cur);
      }
    }

    return answer;
  }
};