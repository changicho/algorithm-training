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

int solution(int size, string& s) {
  int answer = INT_MAX;

  int zeroMax = 0;
  int zeroCount = 0;
  for (int i = 0; i < size; i++) {
    if (s[i] == '0') {
      zeroCount++;
      zeroMax = max(zeroMax, zeroCount);
    } else {
      zeroCount = 0;
    }
  }

  int prefixZeroCount = 0;
  int suffixZeroCount = 0;
  for (int i = 0; i < size; i++) {
    if (s[i] == '0') {
      prefixZeroCount++;
    } else {
      break;
    }
  }
  for (int i = size - 1; i >= 0; i--) {
    if (s[i] == '0') {
      suffixZeroCount++;
    } else {
      break;
    }
  }
  zeroMax = max(zeroMax, prefixZeroCount + suffixZeroCount);

  return zeroMax;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int answer = solution(N, S);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}