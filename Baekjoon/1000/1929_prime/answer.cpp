#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool prime[1000001];

void solution() {
  int S, E;
  cin >> S >> E;

  for (int i = S; i <= E; i++) {
    if (!prime[i]) {
      cout << i << "\n";
    }
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  prime[1] = true;
  int temp;
  for (int i = 2; i < 1000001; i++) {
    if (prime[i]) {
      continue;
    }
    temp = i * 2;

    while (temp < 1000001) {
      prime[temp] = true;
      temp += i;
    }
  }

  solution();

  return 0;
}