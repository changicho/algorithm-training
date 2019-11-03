#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long memo[91][2];

void solution(int test_case) {
  int K;
  cin >> K;

  // find last_memoization
  int last_memoization;
  for (int i = 1; i <= K; i++) {
    if (memo[i][0] == 0) {
      break;
    }

    last_memoization = i;
  }

  for (int index = last_memoization; index < K; index++) {
    long long A = memo[index][0] + memo[index][1], B = memo[index][0];

    memo[index + 1][0] = A;
    memo[index + 1][1] = B;
  }

  cout << "#" << test_case << " " << memo[K][0] << " " << memo[K][1];
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memo[1][0] = 2;
  memo[1][1] = 1;

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}