#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isNotPrime[10000000];
bool check[10000000];

int N;
int nums[10];
bool visited[10];

void dfs(int index, int number) {
  if (!check[number] && !isNotPrime[number]) {
    check[number] = true;
  }

  if (index == N) {
    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    dfs(index + 1, 10 * number + nums[i]);
    visited[i] = false;
  }
}

void solution() {
  int answer = 0;
  string line;
  cin >> line;
  N = line.length();

  for (int i = 0; i < N; i++) {
    nums[i] = line[i] - '0';
  }

  dfs(0, 0);

  for (bool b : check) {
    if (b) answer += 1;
  }

  cout << answer << "\n";
}

void init() {
  isNotPrime[0] = true;
  isNotPrime[1] = true;
  for (int i = 2; i < 10000000; i++) {
    if (isNotPrime[i]) continue;

    for (int j = i * 2; j < 10000000; j += i) {
      isNotPrime[j] = true;
    }
  }
}

void clear() {
  memset(check, 0, sizeof(check));
  memset(visited, 0, sizeof(visited));
  memset(nums, 0, sizeof(nums));
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("./data/input.txt", "r", stdin);
  init();
  int C;
  cin >> C;
  for (int c = 0; c < C; c += 1) {
    clear();
    solution();
  }

  return 0;
}