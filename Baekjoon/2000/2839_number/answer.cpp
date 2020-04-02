#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  int answer = 0;
  cin >> N;

  while (N != 0) {
    if (N < 3) {
      cout << "-1\n";
      return;
    }

    if (N % 5 == 0) {
      answer += N / 5;
      N = 0;
    }

    if (N >= 3) {
      N -= 3;
      answer += 1;
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