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

int convert(int time) {
  int h = time / 100;
  int m = time % 100;

  return h * 60 + m;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs,
             int startday) {
  startday--;

  int size = schedules.size();
  int answer = 0;

  for (int i = 0; i < size; i++) {
    int target = convert(schedules[i]) + 10;

    int saturday = (5 - startday + 7) % 7;
    int sunday = (6 - startday + 7) % 7;

    int count = 0;
    for (int d = 0; d < 7; d++) {
      if (d == saturday || d == sunday) continue;

      int t = convert(timelogs[i][d]);

      if (t <= target) count++;
    }

    if (count == 5) answer++;
  }

  return answer;
}