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

long long combi[5001][5001] = {
    0,
};

auto solution(int n, long long m, vector<int> &counts) {
  long long answer = 1;

  int sum = 0;
  for (int &c : counts) {
    sum += c;
    answer *= combi[sum][c];
    answer %= m;
  }

  return answer;
}

void init(int mod) {
  combi[0][0] = 1;
  for (int i = 1; i <= 5000; i++) {
    combi[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % mod;
    }
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  long long M;
  cin >> T >> M;

  init(M);

  for (int tc = 1; tc <= T; ++tc) {
    int N;
    cin >> N;

    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
      cin >> C[i];
    }

    auto answer = solution(N, M, C);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}