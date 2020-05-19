#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int A, B;
  cin >> A >> B;
  cout << A + B << "\n";
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