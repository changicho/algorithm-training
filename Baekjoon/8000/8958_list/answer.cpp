#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string line;
    cin >> line;
    int score = 0;
    int continuous = 0;

    for (char c : line) {
      if (c == 'O') {
        continuous += 1;
        score += continuous;
      } else {
        continuous = 0;
      }
    }

    cout << score << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}