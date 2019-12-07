#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalin(string word) {
  int length = word.length();

  for (int i = 0; i < length / 2; i += 1) {
    if (word[i] != word[length - 1 - i]) {
      return false;
    }
  }
  return true;
}

void solution(int test_case) {
  int answer = -1, N;
  string str;

  cin >> str;

  N = str.length();

  for (int n = N; n >= 0; n -= 1) {
    for (int i = 0; i <= N - n; i++) {
      string word = str.substr(i, n);
      if (isPalin(word)) {
        answer = n;
        break;
      }
    }

    if (answer != -1) {
      break;
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