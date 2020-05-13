#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string bigO;
  long long N, tc, tl;
  long long LIMIT = 100000000;

  cin >> bigO >> N >> tc >> tl;

  long long calcul = 1;

  calcul = tc;
  if (bigO == "O(N)") {
    calcul *= N;
  } else if (bigO == "O(N^2)") {
    calcul *= N * N;
  } else if (bigO == "O(N^3)") {
    calcul *= N * N;
    if (calcul <= LIMIT * tl) {
      calcul *= N;
    }
  } else if (bigO == "O(2^N)") {
    for (int i = 0; i < N && calcul <= LIMIT * tl; i++) {
      calcul *= 2;
    }
  } else if (bigO == "O(N!)") {
    for (int i = 1; i <= N && calcul <= LIMIT * tl; i++) {
      calcul *= i;
    }
  }

  if (calcul <= LIMIT * tl) {
    cout << "May Pass.";
  } else {
    cout << "TLE!";
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    solution();
  }

  return 0;
}