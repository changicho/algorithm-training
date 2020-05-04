#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M;
  vector<int> arr;

  cin >> N;

  arr.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  cin >> M;
  for (int i = 0; i < M; i++) {
    int target;
    cin >> target;

    int answer = upper_bound(arr.begin(), arr.end(), target) -
                 lower_bound(arr.begin(), arr.end(), target);

    cout << answer << " ";
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