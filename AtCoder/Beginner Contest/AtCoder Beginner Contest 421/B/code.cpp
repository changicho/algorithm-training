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

long long convert(long long num) {
  long long ret = 0;
  while (num > 0) {
    ret *= 10;
    ret += num % 10;
    num /= 10;
  }
  return ret;
}

auto solution(long long x, long long y) {
  long long before = x;
  long long cur = y;

  for (long long i = 3; i <= 10; i++) {
    long long temp = convert(before + cur);
    before = cur;
    cur = temp;
  }

  return cur;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  long long X, Y;
  cin >> X >> Y;

  auto answer = solution(X, Y);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}