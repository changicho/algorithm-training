#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use queue

class Vector2D {
 private:
  queue<int> q;

 public:
  Vector2D(vector<vector<int>>& vec) {
    for (vector<int>& cur : vec) {
      for (int num : cur) {
        q.push(num);
      }
    }
  }

  int next() {
    int ret = q.front();
    q.pop();

    return ret;
  }

  bool hasNext() {
    return !q.empty();
  }
};

// use index

class Vector2D {
 private:
  int outer = 0, inner = 0;
  vector<vector<int>> array;

  void trimIndex() {
    while (outer != array.size() && inner == array[outer].size()) {
      outer++;
      inner = 0;
    }
  }

 public:
  Vector2D(vector<vector<int>>& vec) {
    array = vec;
  }

  int next() {
    trimIndex();
    int ret = array[outer][inner];
    inner += 1;
    return ret;
  }

  bool hasNext() {
    trimIndex();
    return outer < array.size();
  }
};

// use iterator

class Vector2D {
  vector<vector<int>>::iterator outer, iEnd;
  int inner = 0;

  void trimIterator() {
    while (outer != iEnd && inner == (*outer).size()) {
      outer++;
      inner = 0;
    }
  }

 public:
  Vector2D(vector<vector<int>>& vec2d) {
    outer = vec2d.begin();
    iEnd = vec2d.end();
  }

  int next() {
    trimIterator();
    int ret = (*outer)[inner];
    inner++;
    return ret;
  }

  bool hasNext() {
    trimIterator();
    return outer != iEnd;
  }
};