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

vector<long long> solution(int size, vector<int> &a, vector<int> &b, int qSize,
                           vector<vector<int>> &queries) {
  vector<long long> answer;

  long long sum = 0;
  for (int i = 0; i < size; i++) {
    sum += min(a[i], b[i]);
  }

  for (vector<int> &query : queries) {
    int c = query[0], x = query[1], y = query[2];

    sum -= min(a[x], b[x]);
    if (c == 0) {
      a[x] = y;
    } else {
      b[x] = y;
    }

    sum += min(a[x], b[x]);
    answer.push_back(sum);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, Q;
  cin >> N >> Q;

  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  vector<vector<int>> queries(Q);
  for (int i = 0; i < Q; i++) {
    char c;
    cin >> c;

    int x, y;
    cin >> x >> y;

    queries[i] = {c == 'A' ? 0 : 1, x - 1, y};
  }

  auto answer = solution(N, A, B, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}