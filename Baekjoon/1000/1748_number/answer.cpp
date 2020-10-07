#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int answer = 0;
  int N;
  cin >> N;

  int count = 1;
  int temp = 10;

  while (temp <= N) {
    answer += (temp * 0.9) * count;
    count += 1;
    temp *= 10;
  }

  N -= temp / 10;
  answer += (N + 1) * count;

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}