#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  vector<int> ranks(N + 1);

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    ranks[a] = b;
  }

  int before = ranks[1];
  int answer = 1;
  for (int i = 2; i <= N; i++) {
    if (ranks[i] <= before) {
      before = ranks[i];
      answer++;
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    solution();
  }

  return 0;
}