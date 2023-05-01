#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use BST set
// time : O((N + M) * log_2(N))
// space : O(N)
class SmallestInfiniteSet {
 private:
  int start = 1;
  set<int> numSet;

 public:
  SmallestInfiniteSet() {}

  int popSmallest() {
    if (numSet.empty()) {
      int ret = start;
      start++;
      return ret;
    }
    int minimum = *numSet.begin();
    numSet.erase(minimum);
    return minimum;
  }

  void addBack(int num) {
    if (num >= start) return;

    numSet.insert(num);
  }
};