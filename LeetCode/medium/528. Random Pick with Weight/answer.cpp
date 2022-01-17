#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefix sum with binary search

class Solution {
 private:
  vector<float> preSum;

 public:
  Solution(vector<int>& w) {
    preSum.resize(w.size(), 0);

    preSum[0] = w.front();
    for (int i = 1; i < w.size(); i++) {
      preSum[i] = preSum[i - 1] + w[i];
    }
  }

  int pickIndex() {
    float target = (float)rand() / RAND_MAX * preSum.back();

    int index =
        upper_bound(preSum.begin(), preSum.end(), target) - preSum.begin();
    return index;
  }
};

// use prefix sum with binary search (rand of range)

class Solution {
 private:
  vector<int> preSum;

 public:
  Solution(vector<int>& w) {
    preSum.resize(w.size(), 0);

    // fill prefixSum
    preSum[0] = w.front();
    for (int i = 1; i < w.size(); i++) {
      preSum[i] = preSum[i - 1] + w[i];
    }
  }

  int pickIndex() {
    int target = rand() % (preSum.back());

    int index =
        upper_bound(preSum.begin(), preSum.end(), target) - preSum.begin();
    return index;
  }
};