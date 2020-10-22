#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  for (int i = 1; i <= 9; i++) {
    cout << N << " * " << i << " = " << N * i << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}