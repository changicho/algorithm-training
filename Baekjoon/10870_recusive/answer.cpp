#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fibo(int n) {
  if (n <= 0) {
    return 0;
  }
  if (n <= 2) {
    return 1;
  }
  return fibo(n - 1) + fibo(n - 2);
}

void solution() {
  int N;
  cin >> N;

  cout << fibo(N) << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}