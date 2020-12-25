#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  double sum = 0;
  vector<double> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  double avg = sum / N;
  int count = 0;

  for (double d : arr) {
    if (d > avg) count += 1;
  }

  cout << (double)count / (double)N * 100 << "%\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(3);

  int C;
  cin >> C;

  while (C--) {
    solution();
  }

  return 0;
}