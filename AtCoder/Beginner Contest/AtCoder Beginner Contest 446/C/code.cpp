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

long long solution(int n, int d, vector<long long>& a, vector<long long>& b) {
  long long answer = 0;

  deque<pair<int, long long>> q;

  for (int i = 0; i < n; i++) {
    q.push_back({i, a[i]});

    int need = b[i];
    while (!q.empty() && need > 0) {
      auto [before, count] = q.front();
      q.pop_front();
      if (count <= need) {
        need -= count;
      } else {
        q.push_front({before, count - need});
        need = 0;
      }
    }

    while (!q.empty() && q.front().first + d <= i) {
      q.pop_front();
    }
  }

  while (!q.empty()) {
    auto [before, count] = q.front();
    q.pop_front();
    answer += count;
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

  for (int t = 0; t < T; t++) {
    int N, D;
    cin >> N >> D;

    vector<long long> A(N);
    vector<long long> B(N);

    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int j = 0; j < N; j++) {
      cin >> B[j];
    }

    auto answer = solution(N, D, A, B);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}