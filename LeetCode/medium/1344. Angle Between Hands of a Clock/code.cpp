#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;

class Solution {
 public:
  double angleClock(int hour, int minutes) {
    double mV = (minutes / 60.0) * 100.0;
    double hV = (hour % 12) / 12.0 * 100.0 + mV / 12.0;

    double val = abs(mV - hV);
    val = min(val, 100.0 - val);

    return val * 360 / 100.0;
  }
};