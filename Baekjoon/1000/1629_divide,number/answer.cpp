#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long A, B, C;

long long mutiple(long long V, long long P) {
  if (P == 0) {
    return 1;
  }

  long long ret = 1;
  long long square = mutiple(V, P / 2);
  ret *= (square * square) % C;

  if (P % 2 == 1) {
    ret *= A;
    ret %= C;
  }

  return ret;
}

void solution() {
  cin >> A >> B >> C;

  long long answer = mutiple(A, B);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}