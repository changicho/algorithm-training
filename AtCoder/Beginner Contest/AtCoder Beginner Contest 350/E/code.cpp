#include <algorithm>
#include <cmath>
#include <functional>
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

double solution(long long n, long long a, long long x, long long y) {
  unordered_map<long long, double> memo;

  function<double(long long)> f = [&](long long n) -> double {
    if (n == 0) return 0;
    if (memo[n]) return memo[n];

    double payX = f(n / a) + x;
    double payY = (double)y * 6 / 5 +
                  (f(n / 2) + f(n / 3) + f(n / 4) + f(n / 5) + f(n / 6)) / 5;

    return memo[n] = min(payX, payY);
  };

  return f(n);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  long long N, A, X, Y;
  cin >> N >> A >> X >> Y;

  double answer = solution(N, A, X, Y);
  cout << answer << endl;

  return 0;
}