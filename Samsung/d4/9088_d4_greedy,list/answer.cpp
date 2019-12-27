#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int answer = 0, N, K, temp, MAX = 0, MIN = 10000;
  int dias[10001] = {
      0,
  };

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    dias[temp] += 1;
    MAX = max(MAX, temp);
    MIN = min(MIN, temp);
  }

  for (int i = MIN; i <= MAX; i++) {
    if (dias[i] == 0) {
      continue;
    }
    temp = 0;
    for (int j = i; j <= min(MAX, i + K); j++) {
      temp += dias[j];
    }
    answer = max(answer, temp);
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