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

long long fibo[46] = {
    0,
};

auto solution(int n, long long x, long long y) {
  if (n == 0) return true;
  if (n == 1) return true;

  long long height = fibo[n];
  long long width = fibo[n + 1];

  long long squareSize = height;

  // compare width, x

  // convert x to lower than square
  if (width / 2 < x) {
    x = width - x + 1;
  }

  if (x + squareSize > width) {
    return false;
  }

  return solution(n - 1, y, x);
}

void init() {
  fibo[1] = fibo[0] = 1;
  for (int i = 2; i <= 45; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  init();

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    long long X, Y;
    cin >> N >> Y >> X;

    auto answer = solution(N, X, Y);

    if (answer) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}