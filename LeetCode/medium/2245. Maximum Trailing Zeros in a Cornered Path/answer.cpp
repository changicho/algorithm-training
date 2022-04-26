#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefix sum with prime factor
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  struct Pair {
    int two, five;

    Pair operator+(const Pair &b) const { return {two + b.two, five + b.five}; }
    Pair operator-(const Pair &b) const { return {two - b.two, five - b.five}; }
  };

  int countFactor(int number, int factor) {
    int count = 0;
    while (number % factor == 0) {
      number /= factor;
      count++;
    }
    return count;
  }

  int countPair(Pair p) { return min(p.two, p.five); }

 public:
  int maxTrailingZeros(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    // count 2, 5
    vector<vector<Pair>> fromTop(rows + 1, vector<Pair>(cols + 1, {0, 0}));
    vector<vector<Pair>> fromLeft(rows + 1, vector<Pair>(cols + 1, {0, 0}));

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int num = grid[y][x];
        Pair factors = {countFactor(num, 2), countFactor(num, 5)};

        fromTop[y + 1][x] = fromTop[y][x] + factors;
        fromLeft[y][x + 1] = fromLeft[y][x] + factors;
      }
    }

    int countZero = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int num = grid[y][x];
        Pair v1 = fromTop[y + 1][x], v2 = fromTop[rows][x] - fromTop[y][x];
        Pair h1 = fromLeft[y][x + 1], h2 = fromLeft[y][cols] - fromLeft[y][x];
        // to remove duplicate
        Pair cur = {countFactor(num, 2), countFactor(num, 5)};

        countZero =
            max({countZero, countPair(v1 + h1 - cur), countPair(v1 + h2 - cur),
                 countPair(v2 + h1 - cur), countPair(v2 + h2 - cur)});
      }
    }
    return countZero;
  }
};