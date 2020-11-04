#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int answer;
  int N;
  string line;
  vector<int> patternIndex;

  cin >> N >> line;

  patternIndex.resize(N, 0);

  for (int lineIdx = 1, patternIdx = 0; lineIdx < N; lineIdx++) {
    while (patternIdx > 0 && line[lineIdx] != line[patternIdx]) {
      patternIdx = patternIndex[patternIdx - 1];
    }
    if (line[lineIdx] == line[patternIdx]) {
      patternIdx++;
      patternIndex[lineIdx] = patternIdx;
    }
  }

  answer = N - patternIndex[N - 1];
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}