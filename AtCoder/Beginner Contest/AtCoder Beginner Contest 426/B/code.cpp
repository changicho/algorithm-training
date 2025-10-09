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

auto solution(string &s) {
  int counts[26] = {
      0,
  };

  for (char &c : s) {
    counts[c - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (counts[i] == 1) {
      return (char)('a' + i);
    }
  }

  return 'a';
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  string S;
  cin >> S;

  auto answer = solution(S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}