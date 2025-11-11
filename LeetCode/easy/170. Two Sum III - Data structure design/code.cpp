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

// use hash map
// time : O(N)
// space : O(N)
class TwoSum {
 private:
  unordered_map<long, int> count;

 public:
  TwoSum() {}

  void add(int number) { count[number]++; }

  bool find(int value) {
    if (value % 2 == 0) {
      if (count.count(value / 2) > 0 && count[value / 2] >= 2) return true;
    }

    for (auto [key, val] : count) {
      long remain = value - key;
      if (remain == key) continue;

      if (count.count(remain)) return true;
    }

    return false;
  }
};
