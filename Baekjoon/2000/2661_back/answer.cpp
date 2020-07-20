#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string answer = "";
bool makeAnswer = false;

bool canMake(string line) {
  int length = line.length();
  for (int size = 1; size <= length / 2; size++) {
    int firstStart = length - (size * 2);
    int secondStart = length - size;

    string first = "";
    string second = "";

    for (int j = 0; j < size; j++) {
      first += line[firstStart + j];
      second += line[secondStart + j];
    }
    if (first == second) {
      return false;
    }
  }
  return true;
}

void dfs(int index, string line) {
  if (line.length() == N) {
    if (answer > line) {
      answer = line;
      makeAnswer = true;
    }
    return;
  }
  if (makeAnswer) {
    return;
  }

  string newLine;

  for (int i = 1; i <= 3; i++) {
    newLine = line;
    newLine += i + '0';

    if (canMake(newLine)) {
      dfs(index + 1, newLine);
    }
  }
}

void solution() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    answer += '9';
  }

  dfs(0, "");

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}