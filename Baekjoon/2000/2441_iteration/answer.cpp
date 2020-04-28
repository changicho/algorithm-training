#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool stars[101][101];

void solution() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j >= i; j--) {
      stars[i][j] = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (stars[i][j]) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}