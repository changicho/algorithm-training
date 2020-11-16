#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int array[9];

  for (int i = 0; i < 9; i++) {
    cin >> array[i];
  }

  int maxIndex = 0;
  int maxValue = array[0];

  for (int i = 0; i < 9; i++) {
    if (array[i] > maxValue) {
      maxValue = array[i];
      maxIndex = i;
    }
  }

  cout << maxValue << "\n";
  cout << maxIndex + 1 << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}