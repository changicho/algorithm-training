#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use union find
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  unordered_map<int, int> parents;
  int parentCount = 0;

  int convert(int y, int x) { return y * 100000 + x; };

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (a > b) swap(a, b);

    parentCount--;
    parents[b] = a;
  }

 public:
  int removeStones(vector<vector<int>> &stones) {
    int size = stones.size();
    unordered_map<int, unordered_set<int>> boardYx, boardXy;

    // initialize
    parentCount = size;
    for (vector<int> &stone : stones) {
      int y = stone[1], x = stone[0];

      boardYx[y].insert(x);
      boardXy[x].insert(y);

      int index = convert(y, x);
      parents[index] = index;
    }

    for (vector<int> &stone : stones) {
      int y = stone[1], x = stone[0];
      int cur = convert(y, x);

      for (int curX : boardYx[y]) {
        int next = convert(y, curX);
        merge(cur, next);
      }
      for (int curY : boardXy[x]) {
        int next = convert(curY, x);
        merge(cur, next);
      }
    }

    return size - parentCount;
  }
};

// use union find
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  int convert(int y, int x) { return y * 100000 + x; };

  unordered_map<int, int> parents;
  int parentCount = 0;

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    a = find(a), b = find(b);

    if (a == b) return;
    if (a > b) swap(a, b);

    parentCount--;
    parents[b] = a;
  }

 public:
  int removeStones(vector<vector<int>> &stones) {
    int size = stones.size();
    unordered_map<int, unordered_set<int>> boardYx, boardXy;

    // initialize
    parentCount = size;
    for (vector<int> &stone : stones) {
      int y = stone[1], x = stone[0];

      boardYx[y].insert(x);
      boardXy[x].insert(y);

      int index = convert(y, x);
      parents[index] = index;
    }

    for (auto &[y, xs] : boardYx) {
      int curX = *xs.begin();
      for (int x : xs) {
        merge(convert(y, curX), convert(y, x));
      }
    }

    for (auto &[x, ys] : boardXy) {
      int curY = *ys.begin();
      for (int y : ys) {
        merge(convert(curY, x), convert(y, x));
      }
    }

    return size - parentCount;
  }
};