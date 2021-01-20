#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  vector<int> arr(N);
  vector<int> dp_asc(N, 1);
  vector<int> dp_desc(N, 1);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int cur = 0; cur < N; cur++) {
    for (int index = 0; index <= cur; index++) {
      if (arr[index] < arr[cur] && dp_asc[cur] <= dp_asc[index]) {
        dp_asc[cur] = dp_asc[index] + 1;
      }
    }
  }

  for (int cur = N - 1; cur >= 0; cur--) {
    for (int index = N - 1; index >= cur; index--) {
      if (arr[cur] > arr[index] && dp_desc[index] >= dp_desc[cur]) {
        dp_desc[cur] = dp_desc[index] + 1;
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < N; i++) {
    answer = max(answer, dp_asc[i] + dp_desc[i] - 1);
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}