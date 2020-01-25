#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  long long X, Y, answer;
  long long Z, new_Z;

  cin >> X >> Y;

  long long start = 0, end = X, mid;

  Z = 100 * Y / X;

  if (Z >= 99) {
    cout << "-1\n";
    return;
  }

  while (end - start >= 0) {
    mid = (start + end) / 2;

    new_Z = 100 * (Y + mid) / (X + mid);

    if (new_Z > Z) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  cout << start << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}