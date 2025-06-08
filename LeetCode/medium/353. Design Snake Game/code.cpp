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

// use deque & queue & hash set
// time : O(N)
// space : O(M)
class SnakeGame {
 private:
  struct Axis {
    int y, x;
  };

  unordered_map<char, Axis> dirs = {
      {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

  int width, height;

  unordered_set<int> snakeSet;
  deque<Axis> snake;
  queue<int> foods;

  int score = 0;

  int convert(int y, int x) { return y * 1e5 + x; }

 public:
  SnakeGame(int width, int height, vector<vector<int>> &food) {
    this->width = width;
    this->height = height;

    for (vector<int> &f : food) {
      int y = f[0], x = f[1];

      foods.push(convert(y, x));
    }

    snake.push_back({0, 0});
    snakeSet.insert(convert(0, 0));
  }

  int move(string direction) {
    if (score == -1) return -1;

    Axis dir = dirs[direction[0]];
    Axis cur = snake.front();

    Axis next = {cur.y + dir.y, cur.x + dir.x};

    if (next.y < 0 || next.y >= height || next.x < 0 || next.x >= width) {
      return score = -1;
    }

    bool matchFood = !foods.empty() && foods.front() == convert(next.y, next.x);

    if (!matchFood) {
      snakeSet.erase(convert(snake.back().y, snake.back().x));
      snake.pop_back();
    }

    if (snakeSet.count(convert(next.y, next.x))) {
      return score = -1;
    }
    snake.push_front(next);
    snakeSet.insert(convert(next.y, next.x));

    if (matchFood) {
      foods.pop();
      score++;
    }

    return score;
  }
};

// use deque & queue & hash set
// time : O(N * M)
// space : O(M)
class SnakeGame {
 private:
  struct Axis {
    int y, x;
  };

  unordered_map<char, Axis> dirs = {
      {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

  int width, height;

  deque<Axis> snake;
  queue<Axis> foods;

  int score = 0;

  bool isSame(Axis &a, Axis &b) { return a.y == b.y && a.x == b.x; }

  bool isCrush(Axis &a) {
    for (Axis &s : snake) {
      if (isSame(a, s)) return true;
    }
    return false;
  }

 public:
  SnakeGame(int width, int height, vector<vector<int>> &food) {
    this->width = width;
    this->height = height;

    for (vector<int> &f : food) {
      int y = f[0], x = f[1];

      foods.push({y, x});
    }

    snake.push_back({0, 0});
  }

  int move(string direction) {
    if (score == -1) return -1;

    Axis dir = dirs[direction[0]];
    Axis cur = snake.front();

    Axis next = {cur.y + dir.y, cur.x + dir.x};

    if (next.y < 0 || next.y >= height || next.x < 0 || next.x >= width) {
      return score = -1;
    }

    bool matchFood = !foods.empty() && isSame(foods.front(), next);

    if (!matchFood) {
      snake.pop_back();
    }

    if (isCrush(next)) {
      return score = -1;
    }
    snake.push_front(next);

    if (matchFood) {
      foods.pop();
      score++;
    }

    return score;
  }
};
