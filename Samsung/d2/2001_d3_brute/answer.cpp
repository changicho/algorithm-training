#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int map[15][15];

void solution(int test_case) {
  int N, M, answer = 0;

  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> map[y][x];
    }
  }

  for (int y = 0; y < N - M + 1; y++) {
    for (int x = 0; x < N - M + 1; x++) {
      int temp = 0;

      for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
          temp += map[y + i][x + j];
        }
      }

      answer = max(temp, answer);
    }
  }

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}