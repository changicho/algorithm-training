#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
  }

  cout << N - 1 << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int testCase = 0; testCase < T; testCase++) {
    solution();
  }

  return 0;
}