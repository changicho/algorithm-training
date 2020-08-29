#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int divide(int number, int count) {
  if (count == 1) {
    return number;
  }

  int val = divide(number, count / 2);
  if (count % 2 == 1) {
    return (val * val * number) % 10;
  }
  return (val * val) % 10;
}

void solution() {
  int A, B;
  cin >> A >> B;

  A = A % 10;
  int temp = divide(A, B);

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