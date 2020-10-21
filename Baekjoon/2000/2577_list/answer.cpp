#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  long long A, B, C;
  int count[10] = {
      0,
  };

  cin >> A >> B >> C;

  long long multi = A * B * C;
  string str = to_string(multi);

  for (char c : str) {
    count[c - '0'] += 1;
  }

  for (int i : count) {
    cout << i << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}