#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two hash map
// time : O(1)
// space : O(P + S^2)
class UndergroundSystem {
 private:
  struct CheckIn {
    string station;
    int time;
  };

  struct History {
    double totalTime;
    int count;
  };

  // id, {station, check in time}
  unordered_map<int, CheckIn> checkInMap;
  // path, {total time, count}
  unordered_map<string, History> historyMap;

 public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    checkInMap[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    auto checkIn = checkInMap[id];
    // erase from check in
    checkInMap.erase(id);

    string path = checkIn.station + "_" + stationName;
    double totalTime = t - checkIn.time;
    historyMap[path].totalTime += totalTime;
    historyMap[path].count++;
  }

  double getAverageTime(string startStation, string endStation) {
    string path = startStation + "_" + endStation;
    auto& History = historyMap[path];
    return History.totalTime / History.count;
  }
};
