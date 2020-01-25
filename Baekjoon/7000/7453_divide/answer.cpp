#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  vector<int> A, B, C, D;
  long long count = 0;

  cin >> N;

  A.resize(N);
  B.resize(N);
  C.resize(N);
  D.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  vector<long long> sumAB, sumCD;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sumCD.push_back(C[i] + D[j]);
    }
  }

  sort(sumCD.begin(), sumCD.end());

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      long long first = A[i] + B[j];
      int high =
          upper_bound(sumCD.begin(), sumCD.end(), -first) - sumCD.begin();
      int low = lower_bound(sumCD.begin(), sumCD.end(), -first) - sumCD.begin();

      if (first + sumCD[low] == 0) count += high - low;
    }
  }

  cout << count << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}