#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, start_window = 0, end_window = 0;
  long long count = 0, M;
  int arr[10000];

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  while (end_window != N) {
    long long sum = 0;
    for (int i = start_window; i <= end_window; i++) {
      sum += (long long)arr[i];
    }

    if (sum == M) {
      count += 1;
      start_window += 1;
    }
    if (sum < M) end_window += 1;
    if (sum > M) start_window += 1;

    if (start_window > end_window) end_window = start_window;
  }

  cout << count << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}