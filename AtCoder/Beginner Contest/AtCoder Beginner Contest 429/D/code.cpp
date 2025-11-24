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

auto solution(int size, long long m, int c, vector<long long>& positions) {
  long long answer = 0;

  // double cycle
  for (int i = 0; i < size; i++) {
    positions.push_back(positions[i] + m);
  }

  sort(positions.begin(), positions.end());

  for (int i = 1; i < size + 1; i++) {
    // (positions[i-1]+0.5) ~ (positions[i]-0.5) -> same result
    long long before = positions[i - 1];
    long long cur = positions[i];

    long long duplicated = cur - before;

    // cur -> met c people position
    // already meet cur
    long long nextStop = positions[(i - 1) + c];

    long long metCount =
        upper_bound(positions.begin(), positions.end(), nextStop) -
        lower_bound(positions.begin(), positions.end(), cur);

    answer += metCount * duplicated;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  long long M;
  int C;
  cin >> N >> M >> C;

  vector<long long> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto answer = solution(N, M, C, A);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}