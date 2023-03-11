#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[1026][1026];
int memo[1026][1026];

void solution() {
  int N, M;
  cin >> N >> M;

  for (int y = 1; y <= N; y++) {
    for (int x = 1; x <= N; x++) {
      cin >> arr[y][x];

      memo[y][x] =
          arr[y][x] + memo[y][x - 1] + memo[y - 1][x] - memo[y - 1][x - 1];
    }
  }

  for (int i = 0; i < M; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int answer = memo[x2][y2] - memo[x1 - 1][y2] - memo[x2][y1 - 1] +
                 memo[x1 - 1][y1 - 1];

    cout << answer << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}