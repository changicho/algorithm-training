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

// use BST set
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int kEmptySlots(vector<int>& bulbs, int k) {
    int size = bulbs.size();

    set<int> s;

    for (int i = 0; i < size; i++) {
      int left = -1, right = -1;

      if (s.empty()) {
        s.insert(bulbs[i]);
        continue;
      }

      auto up = s.upper_bound(bulbs[i]);
      auto low = prev(up);

      if (up != s.end()) {
        right = *up - bulbs[i] - 1;
      }
      if (up != s.begin()) {
        left = bulbs[i] - *low - 1;
      }

      if (left == k || right == k) return i + 1;

      s.insert(bulbs[i]);
    }

    return -1;
  }
};

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  int kEmptySlots(vector<int>& bulbs, int k) {
    int size = bulbs.size();

    vector<int> turnOns(size);

    for (int i = 0; i < size; i++) {
      turnOns[bulbs[i] - 1] = i + 1;
    }

    int left = 0, right = k + 1;
    int answer = INT_MAX;
    for (int day = 0; right < size && day < size; day++) {
      if (max(turnOns[left], turnOns[right]) < turnOns[day]) continue;

      if (day == right) {
        answer = min(answer, max(turnOns[left], turnOns[right]));
      }

      left = day, right = k + 1 + day;
    }

    return (answer == INT_MAX) ? -1 : answer;
  }
};