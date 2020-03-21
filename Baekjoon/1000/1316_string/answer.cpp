#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool wordCheck(string word) {
  bool alpha[26];
  memset(alpha, false, sizeof(alpha));

  int before = word[0];
  alpha[word[0] - 'a'] = true;

  for (int i = 0; i < word.length(); i++) {
    if (before != word[i]) {
      if (alpha[word[i] - 'a']) {
        return false;
      }

      alpha[word[i] - 'a'] = true;
      before = word[i];
    }
  }

  return true;
}

void solution() {
  int N;
  int count = 0;
  string word;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> word;

    if (wordCheck(word)) {
      count += 1;
    }
  }
  cout << count << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}