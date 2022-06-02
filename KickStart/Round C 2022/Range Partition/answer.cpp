// 30min

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> prefixSums;

vector<int> canDivide(int N, int X, int Y) {
  double target = (double)X / (double)Y;
  int div = X + Y;
  int sum = prefixSums[N];

  // edge case
  if (div > sum) return {};
  if (sum % div != 0) return {};

  int alanTarget = (sum / div) * X;

  vector<int> res;
  set<int> nums;
  for (int n = 1; n <= N; n++) {
    nums.insert(n);
  }

  while (alanTarget > 0 && !nums.empty()) {
    auto it = prev(nums.upper_bound(alanTarget));

    if (it == nums.end()) return {};

    int cur = *it;
    nums.erase(cur);
    alanTarget -= cur;
    res.push_back(cur);
  }

  if (alanTarget > 0) return {};

  return res;
}

void init() {
  prefixSums.resize(5001);

  for (int n = 1; n <= 5000; n++) {
    prefixSums[n] = prefixSums[n - 1] + n;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  init();

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