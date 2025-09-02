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

auto solution(int size, vector<string> &rooms, int x, string &y) {
  return rooms[x - 1] == y;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<string> rooms(N);
  for (int i = 0; i < N; i++) {
    cin >> rooms[i];
  }

  int X;
  string Y;

  cin >> X >> Y;

  auto answer = solution(N, rooms, X, Y);

  // cout << answer << endl;
  cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}