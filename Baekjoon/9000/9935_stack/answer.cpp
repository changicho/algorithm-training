#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string result;
  string line, pattern;

  cin >> line >> pattern;

  result.resize(line.length());
  reverse(pattern.begin(), pattern.end());
  int index = 0;

  for (char c : line) {
    result[index] = c;

    if (c == pattern.front()) {
      bool check = true;

      int size = index + 1 - pattern.length();
      int patternIndex = 0;

      for (int reverseIndex = index; reverseIndex >= size; reverseIndex -= 1) {
        if (reverseIndex < 0 || result[reverseIndex] != pattern[patternIndex]) {
          check = false;
          break;
        }
        patternIndex += 1;
      }

      if (check) index -= pattern.length();
    }
    index++;
  }

  string answer = "";
  if (index == 0) {
    answer = "FRULA";
  } else {
    for (int i = 0; i < index; i++) {
      answer += result[i];
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