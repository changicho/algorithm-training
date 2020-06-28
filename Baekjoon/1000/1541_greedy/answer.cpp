#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  long long answer = 0;
  string line;

  cin >> line;
  bool isPlus = true;

  int temp = 0;
  for (char c : line) {
    if (c == '+') {
      if (!isPlus) {
        answer -= temp;
      } else {
        answer += temp;
      }
      temp = 0;
      continue;
    } else if (c == '-') {
      if (!isPlus) {
        answer -= temp;
      } else {
        answer += temp;
      }
      temp = 0;
      isPlus = false;
      continue;
    }

    temp *= 10;
    temp += c - '0';
  }

  if (!isPlus) {
    answer -= temp;
  } else {
    answer += temp;
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