#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  long long answer = 0, temp = 1;
  string math_expression;
  cin >> math_expression >> math_expression;

  math_expression += '+';

  for (char c : math_expression) {
    if (c == '+') {
      answer += temp;
      temp = 1;
      continue;
    }
    if (c == '*') {
      continue;
    }
    temp *= c - '0';
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