#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use calculate all distance

class Solution {
 private:
  int getDistance(vector<int>& a, vector<int>& b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
  }

 public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    unordered_set<int> s;

    s.insert(getDistance(p1, p2));
    s.insert(getDistance(p1, p3));
    s.insert(getDistance(p1, p4));
    s.insert(getDistance(p2, p3));
    s.insert(getDistance(p2, p4));
    s.insert(getDistance(p3, p4));

    if (s.count(0) == true) {
      return false;
    }
    return s.size() == 2;
  }
};
