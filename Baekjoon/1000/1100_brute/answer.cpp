#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string line;
  int answer = 0;

  for (int i = 0; i < 8; i++) {
    cin >> line;

    for (int j = 0; j < 8; j++) {
      if ((i + j) % 2 == 0 && line[j] == 'F') {
        answer += 1;
      }
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