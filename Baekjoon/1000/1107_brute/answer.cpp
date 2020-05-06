#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer;
int target;
bool check[10];

void dfs(int depth, int num, int count, int limit) {
  if (depth > 0) {
    answer = min(answer, abs(target - num) + count);
  }

  if (depth >= limit) {
    return;
  }

  num *= 10;
  for (int i = 0; i < 10; i++) {
    if (check[i]) continue;

    dfs(depth + 1, num + i, count + 1, limit);
  }
}

void solution() {
  int M;

  cin >> target >> M;

  int length = to_string(target).length();

  for (int i = 0; i < M; i++) {
    int temp;
    cin >> temp;

    check[temp] = true;
  }

  answer = abs(target - 100);

  dfs(0, 0, 0, length + 1);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}