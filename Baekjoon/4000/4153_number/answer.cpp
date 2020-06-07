#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int arr[3];

  while (cin >> arr[0]) {
    cin >> arr[1] >> arr[2];

    if (arr[0] == 0) {
      break;
    }

    sort(arr, arr + 3);

    if (arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0]) {
      cout << "right\n";
    } else {
      cout << "wrong\n";
    }
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