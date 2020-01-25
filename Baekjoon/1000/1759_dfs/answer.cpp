#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
int L, C, answer;
bool alphabet['z' - 'a' + 1];
bool visited['z' - 'a' + 1];

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

// consonant : 자음 2개이상
// vowel : 모음 1개이상

void dfs(int index, int consonant, int vowel) {
  if (L - consonant < 1 || L - vowel < 2) {
    return;
  }

  if (consonant + vowel == L) {
    string word = "";
    for (int i = 0; i <= 'z' - 'a'; i++) {
      if (visited[i]) {
        word += i + 'a';
      }
    }
    cout << word << "\n";
    return;
  }

  for (int i = index; i <= 'z' - 'a'; i++) {
    if (!visited[i] && alphabet[i]) {
      visited[i] = 1;

      bool is_vowel = false;

      for (char c : vowels) {
        if (c == i + 'a') is_vowel = true;
      }

      if (is_vowel)
        dfs(i, consonant, vowel + 1);
      else
        dfs(i, consonant + 1, vowel);

      visited[i] = 0;
    }
  }
}

void solution() {
  cin >> L >> C;
  char c;
  for (int i = 0; i < C; i++) {
    cin >> c;
    alphabet[c - 'a'] = 1;
  }

  dfs(0, 0, 0);

  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}