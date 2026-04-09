#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// hash set
// time : O(1)
// space : O(N)
class PhoneDirectory {
 private:
  unordered_set<int> us;

 public:
  PhoneDirectory(int maxNumbers) {
    for (int i = 0; i < maxNumbers; i++) {
      us.insert(i);
    }
  }

  int get() {
    if (us.empty()) return -1;
    int target = *us.begin();
    us.erase(target);
    return target;
  }

  bool check(int number) {
    if (us.count(number) > 0) {
      return true;
    }
    return false;
  }

  void release(int number) { us.insert(number); }
};
