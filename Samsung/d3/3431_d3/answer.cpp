#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int answer = 0, L, U, X;
  cin >> L >> U >> X;

  if (X < L) {
    answer = L - X;
  }
  if (U < X) {
    answer = -1;
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