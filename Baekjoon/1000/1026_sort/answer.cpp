#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(int a, int b) { return a > b; }

void solution() {
  long long answer = 0;
  int N;

  cin >> N;

  vector<int> A(N);
  vector<int> B(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  sort(A.begin(), A.end(), compare);
  sort(B.begin(), B.end());

  for (int i = 0; i < N; i++) {
    answer += (long long)A[i] * B[i];
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}