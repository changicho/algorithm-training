#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#define MAX 987654321

using namespace std;

int dp[1 << 16];
int N, P;
int table[16][16];

int recursive(int count, int bits) {
  if (count == P) return 0;

  if (dp[bits] != -1) return dp[bits];
  dp[bits] = MAX;

  for (int from = 0; from < N; from++) {
    if (bits & (1 << from)) {
      for (int to = 0; to < N; to++) {
        if (from == to) continue;

        if ((bits & (1 << to)) == 0) {
          int newBits = bits | (1 << to);
          int newCost = recursive(count + 1, newBits) + table[from][to];

          dp[bits] = min(dp[bits], newCost);
        }
      }
    }
  }

  return dp[bits];
}

void solution() {
  int answer = 0;
  string line;
  memset(dp, -1, sizeof(dp));

  cin >> N;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> table[y][x];
    }
  }

  cin >> line >> P;

  int state = 0;
  int count = 0;
  for (int i = 0; i < line.length(); i++) {
    if (line[i] == 'Y') {
      state = state | (1 << i);
      count += 1;
    }
  }

  if (count >= P) {
    cout << "0\n";
    return;
  } else if (count == 0) {
    cout << "-1\n";
    return;
  }
  recursive(count, state);
  answer = dp[state];

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}