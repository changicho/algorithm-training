#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

void solution() {
  int N;
  cin >> N;

  cout << factorial(N) << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}