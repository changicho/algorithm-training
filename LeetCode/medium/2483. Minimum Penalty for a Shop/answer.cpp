#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int bestClosingTime(string customers) {
    int size = customers.size();

    // cost of close at 0
    int curCost = size;
    for (char &c : customers) {
      if (c == 'N') curCost--;
    }

    int cost = curCost;
    int answer = 0;

    // close at i+1
    for (int i = 0; i <= size; i++) {
      char cur = customers[i];

      if (cur == 'Y') {
        curCost--;
      } else {
        curCost++;
      }

      if (curCost < cost) {
        answer = i + 1;
        cost = curCost;
      }
    }

    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int bestClosingTime(string customers) {
    int size = customers.size();

    int minDiff = 0, diff = 0;
    int answer = 0;

    // close at i+1
    for (int i = 0; i <= size; i++) {
      char cur = customers[i];

      if (cur == 'Y') {
        diff--;
      } else {
        diff++;
      }

      if (diff < minDiff) {
        answer = i + 1;
        minDiff = diff;
      }
    }

    return answer;
  }
};