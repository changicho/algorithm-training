#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool isAllSame(string &target) {
  for (int i = 0; i < target.size() - 1; i++) {
    if (target[i] != target[i + 1]) return false;
  }
  return true;
}

bool isPattern(string &target) {
  int size = target.size();
  for (int i = 0; i < size; i++) {
    if (target[i] != target[i % 2]) return false;
  }
  return true;
}

bool isMonotonic(string &target) {
  int diff = target[0] - target[1];
  for (int i = 0; i < target.size() - 1; i++) {
    if (target[i] - target[i + 1] != diff) return false;
  }
  return true;
}

bool isSequence(string &target) {
  int diff = target[0] - target[1];
  return isMonotonic(target) && (abs(diff) == 1);
}

int getCost(string &line, int left, int right) {
  string target = "";
  for (int i = left; i <= right; i++) {
    target += line[i];
  }

  if (isAllSame(target)) return 1;
  if (isSequence(target)) return 2;
  if (isPattern(target)) return 4;
  if (isMonotonic(target)) return 5;
  return 10;
}

int solution(string &line) {
  int size = line.size();
  vector<long> dp(size, INT_MAX);

  for (int i = 2; i <= 4; i++) {
    dp[i] = getCost(line, 0, i);
  }

  for (int i = 5; i < size; i++) {
    long cur = INT_MAX;
    for (int length = 3; length <= 5; length++) {
      cur = min(cur, dp[i - length] + getCost(line, i - length + 1, i));
    }
    dp[i] = cur;
  }

  return dp.back();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    string line;
    cin >> line;
    int answer = solution(line);

    cout << answer << "\n";
  }

  return 0;
}
