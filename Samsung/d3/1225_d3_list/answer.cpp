#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int password[8], MIN, diff, cycle_diff = 0;
  queue<int> new_password;

  cin >> test_case;

  for (int i = 0; i < 8; i++) {
    cin >> password[i];
  }
  MIN = password[0];
  for (int i : password) {
    MIN = min(MIN, i);
  }

  diff = (MIN / 15 - 1) * 15;
  for (int i = 0; i < 8; i++) {
    password[i] -= diff;
    new_password.push(password[i]);
  }

  while (true) {
    int current = new_password.front() - (cycle_diff + 1);
    new_password.pop();

    if (current <= 0) {
      new_password.push(0);
      break;
    }
    new_password.push(current);

    cycle_diff += 1;
    cycle_diff %= 5;
  }

  cout << "#" << test_case << " ";
  while (!new_password.empty()) {
    cout << new_password.front() << " ";
    new_password.pop();
  }
  cout << "\n";
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