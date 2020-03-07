#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int answer = 0;

  for (int i = 0; i < 10; i++) {
    int number;
    cin >> number;

    number % 2 == 1 ? answer += number : 0;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    cout << "#" << test_case << " ";
    solution();
  }

  return 0;
}