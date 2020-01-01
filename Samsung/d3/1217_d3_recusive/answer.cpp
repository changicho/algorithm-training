#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int req(int A, int B) {
  if (B == 1) {
    return A;
  }
  return A * req(A, B - 1);
}

void solution(int test_case) {
  int A, B;

  cin >> test_case >> A >> B;

  cout << "#" << test_case << " " << req(A, B) << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 10;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}