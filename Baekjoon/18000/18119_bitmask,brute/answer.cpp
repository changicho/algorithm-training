#pragma GCC optimize("Ofast")

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M;
  int alphaBits[10000] = {
      0,
  };
  int knowAlpha = 0xffffffff;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;

    for (char c : word) {
      alphaBits[i] |= 1 << (c - 'a');
    }
  }

  char command, alpha;
  for (int i = 0; i < M; i++) {
    cin >> command >> alpha;

    if (command == '1') {
      knowAlpha &= ~(1 << (alpha - 'a'));
    } else {
      knowAlpha |= (1 << (alpha - 'a'));
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
      if ((alphaBits[i] & knowAlpha) == alphaBits[i]) {
        count++;
      }
    }
    cout << count << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}