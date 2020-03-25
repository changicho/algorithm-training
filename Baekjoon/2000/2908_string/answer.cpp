#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string A, B;

  cin >> A >> B;

  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  if (A < B) {
    cout << B;
  } else {
    cout << A;
  }

  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}