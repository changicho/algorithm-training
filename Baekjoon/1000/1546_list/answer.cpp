#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;
  double maximum = 0;
  double arr[1000];
  double sum = 0;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    maximum = max(arr[i], maximum);
  }

  for (int i = 0; i < N; i++) {
    arr[i] = arr[i] / maximum * 100;
    sum += arr[i];
  }

  cout << sum / N << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(8);

  solution();

  return 0;
}