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
int convertToSec(int h, int m, int s) { return h * 60 * 60 + m * 60 + s; }

vector<int> split(int seconds) {
  int h = seconds / (60 * 60);
  int m = (seconds % (60 * 60)) / 60;
  int s = seconds % 60;

  return {h, m, s};
}

vector<double> getAngles(vector<int> time) {
  int h = time[0], m = time[1], s = time[2];

  double hA = double(h % 12) * 30 + double(m) / 2 + (double)s / 120;
  double mA = m * 6 + (double)s / 12;
  double sA = s * 6;

  return {hA, mA, sA};
}

int isMatch(int second) {
  int ret = 0;

  vector<int> before = split(second - 1);
  vector<int> cur = split(second);

  vector<double> beforeA = getAngles(before);
  vector<double> curA = getAngles(cur);

  if (curA[2] == 0) {
    if (beforeA[0] > beforeA[2] && curA[0] <= 360.0) ret++;
    if (beforeA[1] > beforeA[2] && curA[1] <= 360.0) ret++;
  } else {
    if (beforeA[0] > beforeA[2] && curA[0] <= curA[2]) ret++;
    if (beforeA[1] > beforeA[2] && curA[1] <= curA[2]) ret++;
  }

  if (curA[0] == curA[1] && curA[1] == curA[2]) {
    ret--;
  }

  return ret;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
  int startTime = convertToSec(h1, m1, s1);
  int endTime = convertToSec(h2, m2, s2);

  int answer = 0;

  if (startTime == 0 || startTime == 12 * 60 * 60) answer++;
  for (int time = startTime + 1; time <= endTime; time++) {
    int ret = isMatch(time);

    answer += ret;
  }

  return answer;
}