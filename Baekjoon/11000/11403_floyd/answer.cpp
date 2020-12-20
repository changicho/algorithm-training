#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define MAX 987654321

using namespace std;

int N;
int costs[100][100];

void solution() {
  cin >> N;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> costs[y][x];

      if (costs[y][x] == 1) continue;
      costs[y][x] = MAX;
    }
  }

  for (int through = 0; through < N; through++) {
    for (int from = 0; from < N; from++) {
      for (int to = 0; to < N; to++) {
        costs[from][to] = min(costs[from][to], costs[from][through] + costs[through][to]);
      }
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (costs[y][x] == MAX) {
        cout << "0 ";
      } else {
        cout << "1 ";
      }
    }
    cout << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}