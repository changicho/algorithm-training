#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int A, B;
  cin >> A >> B;

  A = A % 10;
  int temp = 1;

  for (int i = 0; i < B; i++) {
    temp = (temp * A) % 10;
  }

  if (temp == 0) {
    temp = 10;
  }
  cout << temp << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    solution();
  }

  return 0;
}