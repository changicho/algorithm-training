#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, Q;
  int start = 0;
  cin >> N >> Q;

  vector<long long> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < Q; i++) {
    int command;
    cin >> command;

    switch (command) {
      case 1: {
        int diff;
        long long value;
        cin >> diff >> value;
        diff -= 1;

        arr[(start + diff) % N] += value;
        break;
      }
      case 2: {
        int iter;
        cin >> iter;

        start = (start + N - iter) % N;
        break;
      }
      case 3: {
        int iter;
        cin >> iter;

        start = (start + iter) % N;
        break;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << arr[(start + i) % N] << " ";
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