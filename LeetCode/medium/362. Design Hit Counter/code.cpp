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

// binary search
// time : O(log_2(N))
// space : O(N)
class HitCounter {
 private:
  vector<int> nums;

 public:
  HitCounter() {}

  void hit(int timestamp) { nums.push_back(timestamp); }

  int getHits(int timestamp) {
    int count = upper_bound(nums.begin(), nums.end(), timestamp) -
                upper_bound(nums.begin(), nums.end(), timestamp - 300);

    return count;
  }
};