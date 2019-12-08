#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int selfNum(int number) {
  int self = number;

  while (number != 0) {
    self += number % 10;
    number /= 10;
  }

  return self;
}

void solution() {
  bool isSelf[10001] = {
      false,
  };

  for (int i = 0; i <= 10000; i++) {
    int index = selfNum(i);

    if (index <= 10000) {
      isSelf[index] = true;
    }
  }

  for (int i = 1; i <= 10000; i++) {
    if (!isSelf[i]) {
      cout << i << "\n";
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