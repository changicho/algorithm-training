#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int answer;
  int X, Y, W, H;

  cin >> X >> Y >> W >> H;

  answer = min(min(X, W - X), min(Y, H - Y));

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}