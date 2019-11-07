#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  string numbers;
  int answer = 0;

  cin >> numbers;
  bool table[10] = {
      0,
  };

  for (int i = 0; i < numbers.length(); i++) {
    int index = numbers[i] - '0';
    if (table[index] == 0) {
      table[index] = true;
    } else {
      table[index] = false;
    }
  }

  for (int i = 0; i < 10; i++) {
    if (table[i]) {
      answer++;
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