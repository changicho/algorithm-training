#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool doesValidArrayExist(vector<int>& derived) {
    int size = derived.size();
    bool converted[100001] = {
        false,
    };
    converted[0] = true;

    for (int i = 0; i < size - 1; i++) {
      int next = i + 1;

      if (derived[i] == 1) {
        converted[next] = !converted[i];
      } else {
        converted[next] = converted[i];
      }
    }

    if (derived[size - 1] == 1) {
      if (converted[0] == converted[size - 1]) return false;
    } else {
      if (converted[0] != converted[size - 1]) return false;
    }
    return true;
  }
};

// use count
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool doesValidArrayExist(vector<int>& derived) {
    int countOne = accumulate(derived.begin(), derived.end(), 0);
    return countOne % 2 == 0;
  }
};