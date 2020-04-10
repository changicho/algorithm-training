#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// factor
// multiple
// neither
void solution() {
  int A, B;

  while (true) {
    cin >> A >> B;

    if (A == 0 && B == 0) {
      return;
    }

    if (A == 0 || B == 0) {
      cout << "neither\n";
      continue;
    }

    if (B % A == 0) {
      cout << "factor\n";
      continue;
    }

    if (A % B == 0) {
      cout << "multiple\n";
      continue;
    }

    cout << "neither\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}