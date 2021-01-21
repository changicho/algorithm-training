#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  long long from, to;

  cin >> from >> to;

  int size = to - from + 1;
  int answer = 0;

  vector<bool> visited(size, false);

  for (long long squared_number = 2; squared_number * squared_number <= to; squared_number++) {
    long long squared = squared_number * squared_number;

    long long number = (from / squared) * squared;
    if (number < from) {
      number += squared;
    }

    while (number <= to) {
      int index = number - from;

      visited[index] = true;
      number += squared;
    }
  }

  for (bool b : visited) {
    if (!b) answer += 1;
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