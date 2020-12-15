#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  long long N;
  int answer = 0;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    if (i % 5 == 0) answer += 1;
    if (i % 25 == 0) answer += 1;
    if (i % 125 == 0) answer += 1;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}