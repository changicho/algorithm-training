#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use map
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long minCost(vector<int>& basket1, vector<int>& basket2) {
    int size = basket1.size();

    map<int, long long> counts;
    for (int& fruit : basket1) {
      counts[fruit]++;
    }
    for (int& fruit : basket2) {
      counts[fruit]--;
    }

    long long minimum = counts.begin()->first;  // minimum value to swap
    vector<long long> swaps;
    for (auto [fruit, count] : counts) {
      // check it can make all pair
      if (count % 2) return -1;

      for (int i = 0; i < abs(count) / 2; i++) {
        swaps.push_back(fruit);
      }
    }

    long long answer = 0;
    for (int i = 0; i < swaps.size() / 2; i++) {
      answer += min(swaps[i], minimum * 2);
    }
    return answer;
  }
};