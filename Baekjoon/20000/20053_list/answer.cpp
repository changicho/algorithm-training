#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  int temp;
  int maxValue = -1000000, minValue = 1000000;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    maxValue = max(maxValue, temp);
    minValue = min(minValue, temp);
  }
  cout << minValue << " " << maxValue << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    solution();
  }

  return 0;
}