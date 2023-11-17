#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use queue
// time : O(1)
// space : O(N)
class MovingAverage {
 private:
  queue<int> q;
  double sum = 0;
  int size = 0;

 public:
  MovingAverage(int size) { this->size = size; }

  double next(int val) {
    if (q.size() >= this->size) {
      sum -= q.front();
      q.pop();
    }
    sum += val;
    q.push(val);

    return sum / q.size();
  }
};
