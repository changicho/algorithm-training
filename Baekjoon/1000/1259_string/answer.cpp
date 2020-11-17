#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrom(string word) {
  int length = word.length();

  for (int i = 0; i < length / 2; i++) {
    if (word[i] != word[length - 1 - i]) return false;
  }
  return true;
}

void solution() {
  string word;

  while (cin >> word) {
    if (word == "0") break;

    if (isPalindrom(word)) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}