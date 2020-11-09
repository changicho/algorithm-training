#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  string word;
  char command, temp;

  cin >> word >> N;

  list<char> editor(word.begin(), word.end());
  auto cursor = editor.end();

  for (int i = 0; i < N; i++) {
    cin >> command;

    switch (command) {
      case 'L': {
        if (cursor != editor.begin()) {
          cursor--;
        }
        break;
      }
      case 'D': {
        if (cursor != editor.end()) {
          cursor++;
        }
        break;
      }
      case 'B': {
        if (cursor != editor.begin()) {
          cursor--;
          cursor = editor.erase(cursor);
        }
        break;
      }
      case 'P': {
        cin >> temp;

        editor.insert(cursor, temp);
        break;
      }
    }
  }

  for (char c : editor) {
    cout << c;
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