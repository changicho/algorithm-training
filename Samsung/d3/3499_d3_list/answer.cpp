#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int N, center;
  string cards[1000];
  cin >> N;

  for (int i = 0; i < N; i += 1) {
    cin >> cards[i];
  }

  center = (N + 1) / 2;

  cout << "#" << test_case << " ";

  for (int i = 0; i < (N + 1) / 2; i += 1) {
    cout << cards[i] << " ";
    if (center == N) {
      break;
    }
    cout << cards[center] << " ";
    center += 1;
  }

  cout << "\n";
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