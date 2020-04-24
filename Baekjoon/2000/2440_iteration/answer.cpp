#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  for (int i = N; i > 0; i--) {
    string line = "";
    for (int j = 0; j < i; j++) {
      line += "*";
    }
    cout << line << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}