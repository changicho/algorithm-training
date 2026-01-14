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

long long solution(int size, int w, vector<int> costs) {
  long long answer = LLONG_MAX;

  long long sum = accumulate(costs.begin(), costs.end(), 0LL);

  long long curSum = 0;
  for (int i = 0; i < size; i++) {
    if (i % (2 * w) < w) {
      curSum += costs[i];
    }
  }
  answer = min(answer, curSum);
  answer = min(answer, sum - curSum);

  for (int i = 0; i < w; i++) {
    long long prevSum = curSum;

    for (int j = i; j < size; j += 2 * w) {
      curSum -= costs[j];
      if (j + w < size) {
        curSum += costs[j + w];
      }
    }

    answer = min(answer, curSum);
    answer = min(answer, sum - curSum);
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
    int N, W;
    cin >> N >> W;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
      cin >> C[i];
    }

    auto answer = solution(N, W, C);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}