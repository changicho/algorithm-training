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

// use queue
// time : O(N)
// time-showFirstUnique : O(1)
// time-add : O(1) (optimized)
// space : O(N)
class FirstUnique {
 private:
  unordered_map<int, int> counts;
  queue<int> q;

 public:
  FirstUnique(vector<int> &nums) {
    for (int &num : nums) {
      counts[num]++;
    }

    for (int &num : nums) {
      if (counts[num] == 1) {
        q.push(num);
      }
    }
  }

  int showFirstUnique() {
    if (q.empty()) return -1;
    return q.front();
  }

  void add(int value) {
    counts[value]++;
    if (counts[value] == 1) {
      q.push(value);
    }

    while (!q.empty() && counts[q.front()] > 1) {
      q.pop();
    }
  }
};
