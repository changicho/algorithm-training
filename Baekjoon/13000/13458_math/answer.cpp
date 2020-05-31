#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, B, C;
  long long answer = 0;
  cin >> N;

  vector<int> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  cin >> B >> C;

  for (int i = 0; i < N; i++) {
    arr[i] -= B;
    answer += 1;
    if (arr[i] > 0) {
      answer += arr[i] / C;

      if (arr[i] % C != 0) {
        answer += 1;
      }
    }
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