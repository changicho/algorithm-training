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
 private:
  int convert(string time) {
    int ret = 0;

    ret += (time[6] - '0') * 10 + (time[7] - '0');
    ret += ((time[3] - '0') * 10 + (time[4] - '0')) * 60;
    ret += ((time[0] - '0') * 10 + (time[1] - '0')) * 60 * 60;

    return ret;
  }

 public:
  int secondsBetweenTimes(string startTime, string endTime) {
    return convert(endTime) - convert(startTime);
  }
};