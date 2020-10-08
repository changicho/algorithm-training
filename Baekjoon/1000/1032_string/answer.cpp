#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  string answer = "";
  cin >> N;

  vector<string> lines(N);

  for (int i = 0; i < N; i++) {
    cin >> lines[i];
  }

  for (int i = 0; i < lines[0].length(); i++) {
    char target = lines[0][i];

    bool isFine = true;
    for (string line : lines) {
      if (line[i] != target) {
        isFine = false;
        break;
      }
    }

    answer += isFine ? target : '?';
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