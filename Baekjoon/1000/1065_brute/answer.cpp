#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isFine(int i) {
  string number = to_string(i);

  int diff = number[1] - number[0];

  for (int i = 2; i < number.length(); i++) {
    if (diff != number[i] - number[i - 1]) {
      return false;
    }
  }
  return true;
}

void solution() {
  int answer = 0;
  int N;

  cin >> N;

  answer = min(9, N);

  for (int i = 10; i <= N; i++) {
    if (isFine(i)) {
      answer++;
    }
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