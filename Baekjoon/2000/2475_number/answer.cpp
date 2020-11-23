#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int arr[5];
  int summation = 0;

  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
    summation += arr[i] * arr[i];
  }

  cout << summation % 10 << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}