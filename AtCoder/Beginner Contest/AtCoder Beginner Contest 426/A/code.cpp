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

auto solution(string &x, string &y) {
  unordered_map<string, int> os;
  // "Ocelot", "Serval", "Lynx"
  os["Ocelot"] = 1;
  os["Serval"] = 2;
  os["Lynx"] = 3;

  return os[y] <= os[x];
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  string X, Y;
  cin >> X >> Y;

  auto answer = solution(X, Y);

  // cout << answer << endl;
  cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}