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

long long solution(int left, int right, int down, int up) {
  long long answer = 0;

  for (int x = left; x <= right; x++) {
    // black case
    if (x % 2 == 0) {
      int curDown = max(down, -abs(x) + 1);
      int curUp = min(up, abs(x) - 1);
      int count = curUp - curDown + 1;

      answer += max(count, 0);
    }
  }

  for (int y = down; y <= up; y++) {
    // black case
    if (y % 2 == 0) {
      int curLeft = max(left, -abs(y));
      int curRight = min(right, abs(y));
      int count = curRight - curLeft + 1;

      answer += max(count, 0);
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int L, R, D, U;
  cin >> L >> R >> D >> U;

  auto answer = solution(L, R, D, U);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}