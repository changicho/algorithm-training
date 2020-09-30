#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long answer = INT_MIN;

long long calculate(long long a, long long b, char operation) {
  switch (operation) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
  }
  return 0;
}

void dfs(int index, long long value, string line) {
  if (index >= line.length()) {
    answer = max(value, answer);
    return;
  }
  char operation = line[index - 1];

  if (index + 2 < line.length()) {
    int next_value = calculate(line[index] - '0', line[index + 2] - '0', line[index + 1]);
    dfs(index + 4, calculate(value, next_value, operation), line);
  }
  dfs(index + 2, calculate(value, line[index] - '0', operation), line);
}

void solution() {
  int N;
  string line;
  cin >> N >> line;

  dfs(2, line[0] - '0', line);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}