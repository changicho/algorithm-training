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

// convert
// time : O(1)
// space : O(1)
class Solution {
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int convert(string date) {
    int month = (date[0] - '0') * 10 + date[1] - '0';
    int day = (date[3] - '0') * 10 + date[4] - '0';

    int ret = 0;
    for (int i = 0; i < month - 1; i++) {
      ret += days[i];
    }
    ret += day;

    return ret;
  }

 public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    int start = max(convert(arriveAlice), convert(arriveBob));
    int end = min(convert(leaveAlice), convert(leaveBob));

    if (end < start) return 0;
    return end - start + 1;
  }
};