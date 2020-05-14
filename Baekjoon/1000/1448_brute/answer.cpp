#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  vector<int> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  for (int i = N - 1; i >= 2; i--) {
    int longest = arr[i];

    for (int j = i - 1; j >= 1; j--) {
      if (longest < arr[j] + arr[j - 1]) {
        cout << arr[i] + arr[j] + arr[j - 1] << "\n";
        return;
      }
    }
  }

  cout << "-1\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}