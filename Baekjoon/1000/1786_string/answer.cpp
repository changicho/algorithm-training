#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  vector<int> answers;
  vector<int> patternIndex;

  string line, pattern;
  getline(cin, line);
  getline(cin, pattern);

  int n = line.size(), m = pattern.size();

  patternIndex.resize(m, 0);

  for (int i = 1, j = 0; i < m; i++) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = patternIndex[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      j++;
      patternIndex[i] = j;
    }
  }

  for (int i = 0, j = 0; i < n; i++) {
    while (j > 0 && line[i] != pattern[j]) {
      j = patternIndex[j - 1];
    }

    if (line[i] == pattern[j]) {
      if (j == m - 1) {
        answers.push_back(i - m + 1);

        j = patternIndex[j];
      } else {
        j++;
      }
    }
  }

  cout << answers.size() << "\n";
  for (int answer : answers) {
    cout << answer + 1 << " ";
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