#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, B, MIN;
int talls[20];

void dfs(int index, int sum) {
  if (sum >= B) {
    MIN = min(MIN, sum - B);
    return;
  }

  if (index >= N) {
    return;
  }

  dfs(index + 1, sum + talls[index]);
  dfs(index + 1, sum);
}

void clear() { MIN = 200000; }

void solution(int test_case) {
  clear();
  cin >> N >> B;

  for (int i = 0; i < N; i++) {
    cin >> talls[i];
  }

  dfs(0, 0);

  cout << "#" << test_case << " " << MIN << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}