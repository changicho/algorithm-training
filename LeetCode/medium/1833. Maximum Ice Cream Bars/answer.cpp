#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());

    int count = 0;
    for (int& cost : costs) {
      if (cost <= coins) {
        count++;
        coins -= cost;
      }
    }
    return count;
  }
};

// use counting sort
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    int size = costs.size();
    int maximum = *max_element(costs.begin(), costs.end());

    vector<int> costsFrequency(maximum + 1);
    for (int& cost : costs) {
      costsFrequency[cost]++;
    }

    int answer = 0;
    for (int cost = 1; cost <= maximum && cost <= coins; ++cost) {
      if (costsFrequency[cost] == 0) continue;

      int count = min(costsFrequency[cost], coins / cost);
      coins -= cost * count;
      answer += count;
    }

    return answer;
  }
};