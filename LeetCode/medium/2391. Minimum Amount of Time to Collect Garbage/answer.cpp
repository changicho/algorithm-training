#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct House {
    int metal, paper, glass;
  };

 public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int size = garbage.size();
    travel.push_back(0);

    vector<House> houses(size);

    House limitIdx = {0, 0, 0};
    for (int i = 0; i < size; i++) {
      House house = {0, 0, 0};

      for (char& c : garbage[i]) {
        if (c == 'M') {
          house.metal++;
        } else if (c == 'G') {
          house.glass++;
        } else if (c == 'P') {
          house.paper++;
        }
      }

      houses[i] = house;
      if (house.metal > 0) limitIdx.metal = i;
      if (house.paper > 0) limitIdx.paper = i;
      if (house.glass > 0) limitIdx.glass = i;
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
      answer += houses[i].metal;
      answer += houses[i].paper;
      answer += houses[i].glass;

      if (limitIdx.metal > i) {
        answer += travel[i];
      }
      if (limitIdx.paper > i) {
        answer += travel[i];
      }
      if (limitIdx.glass > i) {
        answer += travel[i];
      }
    }

    return answer;
  }
};