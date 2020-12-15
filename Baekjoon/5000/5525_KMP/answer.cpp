#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M;
  string line;
  string pattern = "I";

  cin >> N >> M >> line;

  for (int i = 0; i < N; i++) {
    pattern += "OI";
  }

  int patternLength = pattern.length();
  int lineLength = line.length();

  vector<int> patternIndexArr(patternLength, 0);
  for (int curIdx = 1, patternIdx = 0; curIdx < patternLength; curIdx++) {
    while (patternIdx > 0 && pattern[curIdx] != pattern[patternIdx]) {
      patternIdx = patternIndexArr[patternIdx - 1];
    }
    if (pattern[curIdx] == pattern[patternIdx]) {
      patternIdx++;
      patternIndexArr[curIdx] = patternIdx;
    }
  }

  vector<int> answers;

  for (int lineIdx = 0, patternIdx = 0; lineIdx < lineLength; lineIdx++) {
    while (patternIdx > 0 && line[lineIdx] != pattern[patternIdx]) {
      patternIdx = patternIndexArr[patternIdx - 1];
    }

    if (line[lineIdx] == pattern[patternIdx]) {
      if (patternIdx == patternLength - 1) {
        answers.push_back(lineIdx - lineLength + 1);

        patternIdx = patternIndexArr[patternIdx];
      } else {
        patternIdx++;
      }
    }
  }

  cout << answers.size() << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}