#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int alpha_count['Z' + 1];

void solution() {
  int N, answer = 0;
  string line;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> line;
    reverse(line.begin(), line.end());
    int digit = 1;
    for (char c : line) {
      alpha_count[c] += digit;
      digit *= 10;
    }
  }

  sort(alpha_count, alpha_count + 'Z' + 1, greater<int>());

  int digit = 9;
  for (int count : alpha_count) {
    answer += count * digit;
    digit--;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}