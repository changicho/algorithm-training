#include <iostream>
#include <string>

using namespace std;

int score['Z' - 'A' + 1] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6,  6,  6,  7,
                            7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

void solution() {
  string word;
  int answer = 0;

  cin >> word;

  for (char c : word) {
    answer += score[c - 'A'];
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