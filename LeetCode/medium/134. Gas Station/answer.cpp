#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// brute force

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size = gas.size();

    for (int index = 0; index < size; index++) {
      if (canLoop(gas, cost, index)) return index;
    }
    return -1;
  }

  bool canLoop(vector<int>& gas, vector<int>& cost, int start) {
    int size = gas.size();
    int index = start;
    int remain = gas[start];

    while (true) {
      remain -= cost[index];
      index = (index + 1) % size;
      if (remain < 0) return false;
      remain += gas[index];
      if (index == start) break;
    }
    return true;
  }
};

// brute force other

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size = gas.size();

    int totalSum = 0;
    for (int i = 0; i < size; i++) {
      totalSum += gas[i] - cost[i];
    }
    if (totalSum < 0) return -1;

    for (int left = 0; left < size; left++) {
      int sum = 0;
      for (int right = left; right < left + size; right++) {
        sum += gas[right % size] - cost[right % size];

        if (sum < 0) {
          left = right % size;
          break;
        }
      }

      if (sum >= 0) return left;
    }

    return -1;
  }
};

// use two pointer

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size = gas.size();

    int left = size - 1, right = 0;
    int sum = gas[left] - cost[left];

    while (left > right) {
      if (sum >= 0) {
        sum += gas[right] - cost[right];
        right++;
      } else {
        left--;
        sum += gas[left] - cost[left];
      }
    }

    if (sum >= 0) return left;
    return -1;
  }
};
