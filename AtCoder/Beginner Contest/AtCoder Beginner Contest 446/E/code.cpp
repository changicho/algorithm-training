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

long long solution(int m, int a, int b) {
  long long answer = 0;

  // 0 = unvisited
  // 1 = visiting
  // 2 = safe
  // 3 = bad
  vector<vector<int>> state(m, vector<int>(m, 0));

  function<bool(int, int)> recursive = [&](int x, int y) {
    if (x == 0 || y == 0) return false;

    if (state[x][y] == 2) return true;
    if (state[x][y] == 3) return false;
    if (state[x][y] == 1) {
      return true;
    }
    state[x][y] = 1;

    int nx = y;
    int ny = ((long long)a * y + (long long)b * x) % m;

    bool isFine = recursive(nx, ny);

    state[x][y] = isFine ? 2 : 3;
    return isFine;
  };

  for (int x = 0; x < m; x++) {
    for (int y = 0; y < m; y++) {
      if (state[x][y] == 0) {
        recursive(x, y);
      }
    }
  }

  for (int x = 0; x < m; x++) {
    for (int y = 0; y < m; y++) {
      if (state[x][y] == 2) {
        answer++;
      }
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

  int M, A, B;
  cin >> M >> A >> B;

  auto answer = solution(M, A, B);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}