#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int start = -1;
  int size = -1;
  int N, L;
  cin >> N >> L;

  for (int l = L; l <= 100; l++) {
    int t = (l - 1) * l / 2;

    if ((N - t) % l == 0 && (N - t) / l >= 0) {
      start = (N - t) / l;
      size = l;
      break;
    }
  }

  if (start == -1) {
    cout << -1 << "\n";
    return;
  }

  for (int i = 0; i < size; i++) {
    cout << start + i << " ";
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