// 30min

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> canDivide(int N, int X, int Y) {
  double target = (double)X / (double)Y;
  int div = X + Y;
  int sum = N * (N + 1) / 2;

  // edge case
  if (div > sum) return {};
  if (sum % div != 0) return {};

  int alanTarget = (sum / div) * X;

  vector<int> res;

  for (int n = N; n >= 1; n--) {
    if (alanTarget > n) {
      alanTarget -= n;
      res.push_back(n);
    } else {
      res.push_back(min(alanTarget, n));
      alanTarget = 0;
      break;
    }
  }

  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, X, Y;

    cin >> N >> X >> Y;

    vector<int> res = canDivide(N, X, Y);

    cout << "Case #" << testCase << ": ";
    if (res.empty()) {
      cout << "IMPOSSIBLE";
    } else {
      cout << "POSSIBLE\n";
      cout << res.size() << "\n";
      for (int &n : res) {
        cout << n << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}