#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use min heap

class Solution {
 public:
  int connectSticks(vector<int>& sticks) {
    int size = sticks.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int answer = 0;

    // push all sticks
    for (int& s : sticks) {
      minHeap.push(s);
    }

    // doit until there are only one stick
    while (minHeap.size() >= 2) {
      int first = minHeap.top();
      minHeap.pop();
      int second = minHeap.top();
      minHeap.pop();

      // merge minimum two stick in sticks
      answer += first + second;
      // after merge push it to min heap
      minHeap.push(first + second);
    }

    return answer;
  }
};