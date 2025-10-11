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

auto solution(int size, string &s) {
  // {0 count, 1 count}
  vector<vector<int>> countL2R(size, vector<int>(2));
  vector<vector<int>> countR2L(size, vector<int>(2));

  for (int i = 0; i < size; i++) {
    if (i > 0) {
      countL2R[i] = countL2R[i - 1];
    }

    countL2R[i][s[i] - '0']++;
  }
  for (int i = size - 1; i >= 0; i--) {
    if (i < size - 1) {
      countR2L[i] = countR2L[i + 1];
    }

    countR2L[i][s[i] - '0']++;
  }

  int answer = countR2L[1][(s[0] - '0')] * 2 + countR2L[1][!(s[0] - '0')];

  for (int right = 1, left = 0; right < size; right++) {
    if (s[right] != s[right - 1]) {
      left = right;
    }

    char cur = s[right];
    int curI = cur - '0';
    int invertI = !(cur - '0');

    int count = 0;

    if (left > 0) {
      count += countL2R[left - 1][curI] * 2;
      count += countL2R[left - 1][invertI];
    }

    if (right < size - 1) {
      count += countR2L[right + 1][curI] * 2;
      count += countR2L[right + 1][invertI];
    }

    answer = min(answer, count);
  }

  return answer;
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

    auto answer = solution(N, S);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}