#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int H, M;
  int total = 0;
  cin >> H >> M;

  total = H * 60 + M - 45;
  if (total < 0) total += 24 * 60;

  H = total / 60;
  M = total % 60;

  cout << H << " " << M << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}