#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string word;
  cin >> word;

  int alpha['z' - 'a' + 1];

  memset(alpha, -1, sizeof(alpha));

  for (int i = 0; i < word.length(); i++) {
    int index = word[i] - 'a';

    if (alpha[index] == -1) {
      alpha[index] = i;
    }
  }

  for (int i = 0; i < 'z' - 'a' + 1; i++) {
    cout << alpha[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}