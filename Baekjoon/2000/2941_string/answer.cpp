#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * c=
 * c-
 * dz=
 * d-
 * lj
 * nj
 * s=
 * z=
 */

vector<char> table[26];

void solution() {
  string word;
  cin >> word;

  int answer = 0;

  char before = word[0];

  for (int i = 0; i < word.length(); i++) {
    answer += 1;
    switch (word[i]) {
      case 'c': {
        if (i + 1 >= word.length()) {
          break;
        }
        if (word[i + 1] == '=' || word[i + 1] == '-') {
          i += 1;
        }
        break;
      }

      case 'd': {
        if (i + 1 >= word.length()) {
          break;
        }
        if (word[i + 1] == '-') {
          i += 1;
          break;
        }

        if (i + 2 >= word.length()) {
          break;
        }
        if (word[i + 1] == 'z' && word[i + 2] == '=') {
          i += 2;
          break;
        }
        break;
      }

      case 'l': {
        if (i + 1 >= word.length()) {
          break;
        }
        if (word[i + 1] == 'j') {
          i += 1;
          break;
        }
        break;
      }

      case 'n': {
        if (i + 1 >= word.length()) {
          break;
        }
        if (word[i + 1] == 'j') {
          i += 1;
          break;
        }
        break;
      }

      case 's': {
        if (i + 1 >= word.length()) {
          break;
        }
        if (word[i + 1] == '=') {
          i += 1;
          break;
        }
        break;
      }

      case 'z': {
        if (i + 1 >= word.length()) {
          break;
        }
        if (word[i + 1] == '=') {
          i += 1;
          break;
        }
        break;
      }
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