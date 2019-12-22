#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string map[50];

void solution(int test_case) {
  int answer = 0, N, center;
  bool visited[50][50] = {
      false,
  };
  cin >> N;

  center = N / 2;

  for (int i = 0; i < N; i++) {
    cin >> map[i];
    for (int j = abs(center - i); j < N - abs(center - i); j++) {
      answer += map[i][j] - '0';
      visited[i][j] = true;
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