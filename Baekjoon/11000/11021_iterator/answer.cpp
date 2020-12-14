#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int A, B;
    cin >> A >> B;

    cout << "Case #" << i << ": " << A + B << "\n";
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