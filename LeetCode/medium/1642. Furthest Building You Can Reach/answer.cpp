#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use heap
// time : O(N * log_2(N))
// space : O(K)
class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int size = heights.size();
    int answer = 0;

    // O(K)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // O(N)
    for (int i = 1; i < size; i++) {
      int diff = heights[i] - heights[i - 1];

      // use brick or ladder case
      if (diff > 0) {
        // O(log_2(N))
        minHeap.push(diff);
      }

      // use brick case
      if (minHeap.size() > ladders) {
        // O(log_2(N))
        bricks -= minHeap.top();
        minHeap.pop();
      }

      if (bricks < 0) break;

      // can reach to current index
      answer = i;
    }

    return answer;
  }
};

// use binary search
// time : O(N * (log_2(N))^2)
// space : O(N)
class Solution {
 private:
  // O(N * log_2(N))
  bool canReach(vector<int>& heights, int target, int ladders, int bricks) {
    vector<int> diffs;

    long sum = 0;
    // O(N)
    for (int i = 0; i <= target - 1; i++) {
      if (heights[i + 1] > heights[i]) {
        int diff = heights[i + 1] - heights[i];

        diffs.push_back(diff);
        sum += (diff);
      }
    }
    // O(N * log_2(N))
    sort(diffs.begin(), diffs.end());

    // O(N)
    while (!diffs.empty() && ladders > 0) {
      sum -= diffs.back();
      diffs.pop_back();

      ladders--;
    }

    if (sum <= bricks) return true;
    return false;
  }

 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int size = heights.size();

    int answer = 0;
    int left = 0, right = size;

    // O(log_2(N))
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (canReach(heights, mid, ladders, bricks)) {
        answer = mid;
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return answer;
  }
};