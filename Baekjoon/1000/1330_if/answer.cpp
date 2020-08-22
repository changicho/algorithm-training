#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int A, B;
  string answer = "==";
  cin >> A >> B;

  if (A > B) {
    answer = ">";
  } else if (A < B) {
    answer = "<";
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