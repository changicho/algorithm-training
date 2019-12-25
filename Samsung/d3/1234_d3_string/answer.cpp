#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  string answer;
  int index = 0;
  cin >> answer >> answer;

  while (index < answer.length() - 1) {
    if (index >= answer.length()) {
      break;
    }
    if (answer[index] == answer[index + 1]) {
      answer.erase(index, 2);
      index = 0;
      continue;
    }
    index += 1;
  }

  cout << "#" << test_case << " " << answer << "\n";
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