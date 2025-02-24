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

// use hash map & heap
// time : O(N * log_2(N))
// space : O(N)
class NumberContainers {
 private:
  unordered_map<int, priority_queue<int, vector<int>, greater<int>>> indexes;
  unordered_map<int, int> i2num;

 public:
  NumberContainers() {}

  void change(int index, int number) {
    i2num[index] = number;
    indexes[number].push(index);
  }

  int find(int number) {
    while (!indexes[number].empty() && i2num[indexes[number].top()] != number) {
      indexes[number].pop();
    }

    if (indexes[number].empty()) {
      return -1;
    }
    return indexes[number].top();
  }
};
