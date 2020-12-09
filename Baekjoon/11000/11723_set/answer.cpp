#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int M, number;
  int bit = 0;
  string command;
  cin >> M;

  while (M--) {
    cin >> command;

    if (command == "add") {
      cin >> number;

      bit |= (1 << number);
    } else if (command == "remove") {
      cin >> number;

      bit &= ~(1 << number);
    } else if (command == "check") {
      cin >> number;

      if (bit & (1 << number)) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else if (command == "toggle") {
      cin >> number;
      bit = bit ^ (1 << number);
    } else if (command == "all") {
      bit = (1 << 21) - 1;
    } else if (command == "empty") {
      bit = 0;
    }
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}