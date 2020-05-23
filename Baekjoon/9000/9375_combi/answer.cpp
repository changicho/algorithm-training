#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  int answer = 1;
  string cloth, type;

  map<string, int> m;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> cloth >> type;

    m[type] += 1;
  }

  for (auto c : m) {
    answer *= (c.second + 1);
  }

  answer -= 1;

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    solution();
  }

  return 0;
}