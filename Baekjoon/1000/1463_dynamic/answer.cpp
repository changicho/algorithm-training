#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int counts[1000001];  // counts[n] = min(counts[n-1], counts[n/2], counts[n/3]) + 1
  int N;
  cin >> N;

  counts[1] = 0;
  counts[2] = 1;
  counts[3] = 1;

  for (int i = 4; i <= N; i++) {
    int before_count = counts[i - 1];
    if (i % 2 == 0) {
      before_count = min(before_count, counts[i / 2]);
    }
    if (i % 3 == 0) {
      before_count = min(before_count, counts[i / 3]);
    }

    counts[i] = before_count + 1;
  }

  cout << counts[N] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}