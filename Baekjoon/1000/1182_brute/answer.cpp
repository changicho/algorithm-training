#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, S;
int answer = 0;
vector<long long> arr;

void dfs(int index, int sum, int count) {
  if (index == N) {
    if (sum == S && count != 0) answer += 1;

    return;
  }

  dfs(index + 1, sum + arr[index], count + 1);
  dfs(index + 1, sum, count);
}

void solution() {
  cin >> N >> S;
  arr.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  dfs(0, 0, 0);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}