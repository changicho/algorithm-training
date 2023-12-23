#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(N)
class Solution {
 private:
  int calc(vector<vector<int>>& img, int y, int x) {
    int rows = img.size(), cols = img[0].size();
    int count = 0;
    double sum = 0;

    for (int dy = -1; dy <= 1; dy++) {
      for (int dx = -1; dx <= 1; dx++) {
        int ny = y + dy, nx = x + dx;
        if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;
        count++;
        sum += img[ny][nx];
      }
    }

    return sum / count;
  }

 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int rows = img.size(), cols = img[0].size();

    vector<vector<int>> answer(rows, vector<int>(cols));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        answer[y][x] = calc(img, y, x);
      }
    }
    return answer;
  }
};

// use brute force (space optimized)
// time : O(N)
// space : O(1)
class Solution {
 private:
  int calc(vector<vector<int>>& img, int y, int x) {
    int rows = img.size(), cols = img[0].size();
    int count = 0;
    double sum = 0;

    for (int dy = -1; dy <= 1; dy++) {
      for (int dx = -1; dx <= 1; dx++) {
        int ny = y + dy, nx = x + dx;
        if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;
        count++;
        sum += img[ny][nx] % 256;
      }
    }

    return sum / count;
  }

 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int rows = img.size(), cols = img[0].size();

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        img[y][x] += calc(img, y, x) * 256;
      }
    }

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        img[y][x] /= 256;
      }
    }
    return img;
  }
};