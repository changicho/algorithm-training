#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int arr[8];
  int diff = 0;
  bool ascending = true;
  bool descending = true;

  for (int i = 0; i < 8; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < 8; i++) {
    if (arr[i] != i + 1) {
      ascending = false;
      break;
    }
  }

  for (int i = 0; i < 8; i++) {
    if (arr[i] != 8 - i) {
      descending = false;
      break;
    }
  }

  if (ascending) {
    cout << "ascending\n";
  } else if (descending) {
    cout << "descending\n";
  } else {
    cout << "mixed\n";
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