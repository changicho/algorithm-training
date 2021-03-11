#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int nCk[53][53];

void solution() {
  int N;
  cin >> N;

  for (int i = 0; i <= 52; i++) {
    nCk[i][0] = 1;
    nCk[i][i] = 1;
    for (int k = 1; k < i; k++) {
      nCk[i][k] = nCk[i - 1][k - 1] + nCk[i - 1][k];
      nCk[i][k] %= 10007;
      nCk[i][i - k] = nCk[i][k];
    }
  }

  int answer = 0;
  for (int i = 1; i <= 13 && N - 4 * i >= 0; ++i) {
    if (i % 2 == 1) {
      answer += nCk[52 - 4 * i][N - 4 * i] * nCk[13][i] % 10007;
      answer %= 10007;
    } else {
      answer -= nCk[52 - 4 * i][N - 4 * i] * nCk[13][i] % 10007;
      answer += 10007;
      answer %= 10007;
    }
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