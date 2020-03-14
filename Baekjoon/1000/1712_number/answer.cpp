#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  long long A, B, C;

  cin >> A >> B >> C;

  if (C == B) {
    cout << "-1\n";
    return;
  }

  long long answer = A / (C - B) + 1;

  if (answer < 0) {
    cout << "-1\n";
    return;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}