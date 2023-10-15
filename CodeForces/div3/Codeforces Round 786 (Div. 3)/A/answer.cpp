#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Response {
  int a, b;
};

// time : O(1)
// space : O(1)
Response solution(int x, int y) {
  if (x > y) return {0, 0};
  if (y % x != 0) return {0, 0};

  int target = y / x;
  int val = 1;

  return {1, target};
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int x, y;

    cin >> x >> y;

    Response res = solution(x, y);
    cout << res.a << " " << res.b << "\n";
  }
}
