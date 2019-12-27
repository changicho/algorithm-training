#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char toggle(char c) {
  if (c == '0') {
    return '1';
  }
  return '0';
}

void solution(int test_case) {
  int answer = 0;
  string memory, current;

  cin >> memory;

  current.assign(memory.length(), '0');

  for (int i = 0; i < memory.length(); i += 1) {
    if (current[i] == memory[i]) {
      continue;
    }

    for (int j = i; j < memory.length(); j++) {
      current[j] = toggle(current[j]);
    }
    answer += 1;
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