#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy position
// time : O(R * C + N^2 * log_2(N^2))
// space : O(N^2)
class Solution {
 public:
  int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
    int pattern[101][101] = {
        0,
    };

    for (int y = 0; y < height; y += sideLength) {
      for (int x = 0; x < width; x += sideLength) {
        // y,x;
        for (int i = 0; i < sideLength && y + i < height; i++) {
          for (int j = 0; j < sideLength && x + j < width; j++) {
            pattern[i][j]++;
          }
        }
      }
    }

    int answer = 0;
    vector<int> counts;
    for (int y = 0; y < sideLength; y++) {
      for (int x = 0; x < sideLength; x++) {
        counts.push_back(pattern[y][x]);
      }
    }
    sort(counts.begin(), counts.end());

    for (int i = 0; i < maxOnes; i++) {
      int cur = counts.back();
      counts.pop_back();
      answer += cur;
    }
    return answer;
  }
};

// use greedy position
// time : O(N^2 * log_2(N^2))
// space : O(N^2)
class Solution {
 public:
  int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
    vector<int> counts;
    for (int y = 0; y < sideLength; y++) {
      for (int x = 0; x < sideLength; x++) {
        int count = (1 + (width - 1 - x) / sideLength) *
                    (1 + (height - 1 - y) / sideLength);
        counts.push_back(count);
      }
    }
    sort(counts.begin(), counts.end());

    int answer = 0;
    for (int i = 0; i < maxOnes; i++) {
      int cur = counts.back();
      counts.pop_back();
      answer += cur;
    }
    return answer;
  }
};