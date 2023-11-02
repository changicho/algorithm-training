#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(NM * log_2(NM))
// space : O(NM)
class Solution {
 private:
  struct Data {
    int dist, worker, bike;

    bool operator<(const Data& other) const {
      if (dist != other.dist) return dist < other.dist;
      if (worker != other.worker) return worker < other.worker;
      return bike < other.bike;
    }
  };

  int findDistance(vector<int>& worker, vector<int>& bike) {
    return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
  }

 public:
  vector<int> assignBikes(vector<vector<int>>& workers,
                          vector<vector<int>>& bikes) {
    // dist, worker, bike
    vector<Data> arr;
    for (int worker = 0; worker < workers.size(); worker++) {
      for (int bike = 0; bike < bikes.size(); bike++) {
        int distance = findDistance(workers[worker], bikes[bike]);
        arr.push_back({distance, worker, bike});
      }
    }

    sort(arr.begin(), arr.end());

    vector<bool> bikeVisited(bikes.size(), false);
    vector<int> worker2bike(workers.size(), -1);

    int choosen = 0;
    for (auto [dist, worker, bike] : arr) {
      if (worker2bike[worker] == -1 && !bikeVisited[bike]) {
        bikeVisited[bike] = true;
        worker2bike[worker] = bike;
        choosen++;

        if (choosen == workers.size()) {
          return worker2bike;
        }
      }
    }

    return worker2bike;
  }
};