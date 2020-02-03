#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M;
  vector<int> memo;

  cin >> N >> M;

  memo.resize(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    int current;
    cin >> current;

    memo[i] = memo[i - 1] + current;
  }

  for (int i = 0; i < M; i++) {
    int from, to;

    cin >> from >> to;

    cout << memo[to] - memo[from - 1] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}