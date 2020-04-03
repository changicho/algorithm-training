#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  long long N, boundary = 1, diff = 6;

  cin >> N;

  while (N > boundary) {
    boundary += diff;
    diff += 6;
  }

  cout << diff / 6 << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}