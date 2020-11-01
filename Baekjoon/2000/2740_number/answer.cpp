#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int A[100][100];
int B[100][100];
int C[100][100];

void solution() {
  int N, M, K;
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> A[y][x];
    }
  }

  cin >> M >> K;

  for (int y = 0; y < M; y++) {
    for (int x = 0; x < K; x++) {
      cin >> B[y][x];
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < K; x++) {
      for (int i = 0; i < M; i++) {
        C[y][x] += A[y][i] * B[i][x];
      }
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < K; x++) {
      cout << C[y][x] << " ";
    }
    cout << "\n";
  }

  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}