#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  long long S;
  int arr[100000];

  cin >> N >> S;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int start = 0, end = 0, answer = N + 1;
  long long sum = arr[0];

  while (true) {
    if (sum >= S) {
      sum -= arr[start];
      answer = min(answer, end - start + 1);

      start += 1;
    }
    if (sum < S) {
      end += 1;
      sum += arr[end];
    }

    if (start > end) {
      end = start;
    }

    if (end == N) break;
  }

  if (answer == N + 1) {
    cout << "0\n";
    return;
  }

  cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}