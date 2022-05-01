#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(N * T)
// space : O(N)
class Solution {
 private:
  struct Person {
    int index, left;
  };

 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int size = tickets.size();

    queue<Person> q;
    for (int i = 0; i < size; i++) {
      q.push({i, tickets[i]});
    }

    int time = 0;
    while (!q.empty()) {
      time++;

      Person cur = q.front();
      q.pop();

      cur.left--;

      if (cur.left > 0) {
        q.push(cur);
      } else if (cur.index == k) {
        break;
      }
    }
    return time;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int size = tickets.size();
    int time = 0;

    for (int i = 0; i < size; i++) {
      // loop case
      time += min(tickets[i], tickets[k]);

      // skip case
      if (i > k && tickets[i] >= tickets[k]) time--;
    }

    return time;
  }
};