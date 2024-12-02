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

// use hash set
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool checkIfExist(vector<int>& arr) {
    unordered_set<int> us;

    for (int& num : arr) {
      if (us.count(num * 2) > 0) return true;
      if (num % 2 == 0 && us.count(num / 2) > 0) return true;
      us.insert(num);
    }
    return false;
  }
};