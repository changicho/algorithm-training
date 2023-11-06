#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use heap
// time : O((N + M) * log_2(N))
// space : O(N)
class SeatManager {
 private:
  priority_queue<int, vector<int>, greater<int>> pq;

 public:
  SeatManager(int n) {
    for (int i = 0; i < n; i++) {
      pq.push(i + 1);
    }
  }

  int reserve() {
    int ret = pq.top();
    pq.pop();

    return ret;
  }

  void unreserve(int seatNumber) { pq.push(seatNumber); }
};