#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use divide and conquerer
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  vector<int> cost;
  vector<int> costSums;
  int answer = 0;

  bool isLeaf(int node, int limit) { return node * 2 > limit; }

  void recursive(int node, int limit, int costSum) {
    costSum += cost[node - 1];

    if (isLeaf(node, limit)) {
      costSums.push_back(costSum);
      return;
    }

    recursive(node * 2, limit, costSum);
    recursive(node * 2 + 1, limit, costSum);
  }

  void divide(int left, int right, int maximum) {
    int curMax = 0;
    for (int i = left; i <= right; i++) {
      int costSum = costSums[i];

      curMax = max(curMax, costSum);
    }

    int diff = maximum - curMax;

    answer += diff;
    for (int i = left; i <= right; i++) {
      costSums[i] += diff;
    }

    if (left == right) return;

    int mid = left + (right - left) / 2;

    divide(left, mid, maximum);
    divide(mid + 1, right, maximum);
  }

 public:
  int minIncrements(int n, vector<int>& cost) {
    this->cost = cost;

    recursive(1, n, 0);

    int maximum = 0;
    for (int& costSum : costSums) {
      maximum = max(maximum, costSum);
    }

    divide(0, costSums.size() - 1, maximum);

    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minIncrements(int n, vector<int>& cost) {
    int answer = 0;

    for (int node = n; node >= 0; node--) {
      int left = node * 2 + 1, right = node * 2 + 2;

      // leaf node case
      if (left >= n) continue;

      int diff = abs(cost[left] - cost[right]);

      // make left and right node's cost equal
      // and increase answer
      answer += diff;
      if (cost[left] < cost[right]) {
        cost[left] += diff;
      } else if (cost[left] > cost[right]) {
        cost[right] += diff;
      }

      cost[node] += cost[left];
    }
    return answer;
  }
};