#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string word;
  cin >> word;
  int table['Z' + 1] = {
      0,
  };

  for (int i = 0; i < word.length(); i++) {
    word[i] = toupper(word[i]);
    table[word[i]] += 1;
  }

  char maxChar = 'A';
  for (int i = 'A' + 1; i < 'Z' + 1; i++) {
    if (table[i] > table[maxChar]) {
      maxChar = i;
    }
  }

  for (int i = 'A' + 1; i < 'Z' + 1; i++) {
    if (i != maxChar && table[i] == table[maxChar]) {
      cout << "?\n";
      return;
    }
  }

  cout << maxChar << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}