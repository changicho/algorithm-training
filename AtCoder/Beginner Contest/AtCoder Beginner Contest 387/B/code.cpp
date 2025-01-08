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

long long solution(int target) {
  long long sum = 0;
  long long allSum = 0;

  for (int y = 1; y <= 9; y++) {
    for (int x = 1; x <= 9; x++) {
      int cur = (y) * (x);
      allSum += cur;

      if (cur != target) {
        sum += cur;
      }
    }
  }

  return sum;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int X;
  cin >> X;

  long long answer = solution(X);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}