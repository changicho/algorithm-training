#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> indexes;

// time : O(650)
// space : O(650)
void init() {
  char first = 'a';
  char second = 'a';

  for (int index = 1; index <= 650; index++) {
    second++;
    if (second > 'z') {
      second = 'a';
      first++;
    }

    while (first == second) {
      second++;

      if (second > 'z') {
        second = 'a';
        first++;

        if (first > 'z') break;
      }
    }

    indexes[{first, second}] = index;
  }
}

int solution(string &word) { return indexes[word]; }

int main() {
  std::ios_base::sync_with_stdio(false);
  init();

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    string word;
    cin >> word;

    int res = solution(word);

    cout << res << "\n";
  }

  return 0;
}