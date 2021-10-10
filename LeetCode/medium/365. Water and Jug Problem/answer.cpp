#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use gcd

class Solution {
 public:
  bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    int gcdVal = gcd(jug1Capacity, jug2Capacity);

    if (targetCapacity % gcdVal == 0 &&
        jug1Capacity + jug2Capacity >= targetCapacity) {
      return true;
    }
    return false;
  }
};

// use ax-by=z

class Solution {
 public:
  bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if (jug1Capacity + jug2Capacity == targetCapacity) return true;
    if (jug1Capacity + jug2Capacity < targetCapacity) return false;

    if (jug1Capacity > jug2Capacity) swap(jug1Capacity, jug2Capacity);

    int volume = 0;
    bool answer = false;

    while (true) {
      if (volume < jug1Capacity) {
        volume += jug2Capacity;
      } else {
        volume -= jug1Capacity;
      }

      if (volume == targetCapacity) {
        answer = true;
        break;
      }

      if (volume == 0) break;
    }

    return answer;
  }
};

// use BFS with backtracking

class Solution {
 private:
  long long convert(pair<int, int> cur) {
    return (long long)cur.first * 1000000 + cur.second;
  }

 public:
  bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if (jug1Capacity + jug2Capacity < targetCapacity) return false;

    queue<pair<int, int>> q;
    unordered_set<long long> s;

    s.insert(convert({jug1Capacity, jug2Capacity}));
    q.push({jug1Capacity, jug2Capacity});

    bool answer = false;
    while (!q.empty()) {
      pair<int, int> cur = q.front();
      q.pop();
      int jug1 = cur.first, jug2 = cur.second;

      if (jug1 + jug2 == targetCapacity) {
        answer = true;
        break;
      }

      vector<pair<int, int>> cases = {{jug1 - min(jug1, jug2Capacity - jug2),
                                       jug2 + min(jug1, jug2Capacity - jug2)},
                                      {jug1 + min(jug2, jug1Capacity - jug1),
                                       jug2 - min(jug2, jug1Capacity - jug1)},
                                      {jug1Capacity, jug2},
                                      {jug1, jug2Capacity},
                                      {0, jug2},
                                      {jug1, 0}};

      for (pair<int, int> next : cases) {
        if (s.count(convert(next)) > 0) continue;

        s.insert(convert(next));
        q.push(next);
      }
    }
    return answer;
  }
};
