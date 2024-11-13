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

// use one pass
// time : O(T + N)
// space : O(T)
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
  int answer = health;

  int table[1001] = {
      0,
  };
  for (vector<int> &a : attacks) {
    table[a[0]] = a[1];
  }
  int TIME_LIMIT = attacks.back()[0];

  int count = 0;
  for (int time = 0; time <= TIME_LIMIT; time++) {
    if (table[time] > 0) {
      answer -= table[time];
      count = 0;
    } else if (answer < health) {
      answer += bandage[1];
      count++;

      if (count == bandage[0]) {
        answer += bandage[2];
        count = 0;
      }

      answer = min(answer, health);
    }

    if (answer <= 0) return -1;
  }

  return answer;
}