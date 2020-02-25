#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int N;
  int pascal[10][10] = {
      1,
  };

  for (int i = 1; i < 10; i++) {
    pascal[i][0] = 1;

    for (int j = 1; j < 10; j++) {
      pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
  }

  cin >> N;

  cout << "#" << test_case << "\n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      cout << pascal[i][j] << " ";
    }
    cout << "\n";
  }
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