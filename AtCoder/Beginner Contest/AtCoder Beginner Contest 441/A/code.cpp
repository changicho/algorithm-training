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

bool solution(int p, int q, int x, int y) {
  bool xOverlapped = p <= x && x < p + 100;
  bool yOverlapped = q <= y && y < q + 100;

  return xOverlapped && yOverlapped;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int P, Q, X, Y;
  cin >> P >> Q >> X >> Y;

  auto answer = solution(P, Q, X, Y);

  // cout << answer << endl;
  cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}