#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long memo[100] = {
    0,
    1,
    1,
};

void solution() {
  for (int i = 3; i <= 90; i += 1) {
    memo[i] = memo[i - 1] + memo[i - 2];
  }

  int N;

  cin >> N;

  cout << memo[N] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}