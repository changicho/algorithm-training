#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  vector<int> arr;
  int N;
  int answer = 0;
  cin >> N;

  arr.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  do {
    int summation = 0;

    for (int i = 0; i < N - 1; i++) {
      summation += abs(arr[i] - arr[i + 1]);
    }

    answer = max(summation, answer);
  } while (next_permutation(arr.begin(), arr.end()));

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}