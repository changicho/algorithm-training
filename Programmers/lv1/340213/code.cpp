#include <algorithm>
#include <climits>
#include <cmath>
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

// use simulation
// time : O(N)
// space : O(1)
int convert(string &time) {
  int s = (time[3] - '0') * 10 + (time[4] - '0');
  int m = (time[0] - '0') * 10 + (time[1] - '0');

  return m * 60 + s;
}

string convertToS(int time) {
  string ret = "";
  int m = time / 60;
  int s = time % 60;

  if (m < 10) ret += '0';
  ret += to_string(m);
  ret += ':';
  if (s < 10) ret += '0';
  ret += to_string(s);
  return ret;
}

string solution(string video_len, string pos, string op_start, string op_end,
                vector<string> commands) {
  int size = convert(video_len);
  int cur = convert(pos);

  int opS = convert(op_start);
  int opE = convert(op_end);

  if (opS <= cur && cur <= opE) {
    cur = opE;
  }
  for (string &command : commands) {
    if (command == "prev") {
      cur = max(cur - 10, 0);
    } else if (command == "next") {
      cur = min(size, cur + 10);
    }

    if (opS <= cur && cur <= opE) {
      cur = opE;
    }
  }

  return convertToS(cur);
}